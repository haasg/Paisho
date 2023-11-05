#include "PaishoPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Paisho/Character/HealthComponent.h"
#include "Paisho/UI/PlayerHudWidget.h"
#include "PaishoCommonController.h"
#include "PaishoGameState.h"
#include "PaishoTeam.h"
#include "Net/UnrealNetwork.h"
#include "Paisho/Character/ArsenalComponent.h"
#include "Paisho/Character/ElementalKnowledgeComponent.h"
#include "Paisho/Character/PaishoHero.h"
#include "Paisho/Character/XpComponent.h"
#include "Paisho/Util/DebugUtil.h"
#include "Paisho/UI/LevelUpSelectorWidget.h"

APaishoPlayerController::APaishoPlayerController()
{
	PlayerHud = nullptr;
}

void APaishoPlayerController::CollectXpForTeam(const int32 Amount)
{
	if(Team)
	{
		Team->CollectXp(Amount);
	}
}


void APaishoPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if(IsLocalPlayerController())
	{
		PlayerHud = CreateWidget<UPlayerHudWidget>(this, PlayerHudClass);
		PlayerHud->AddToViewport();	
	}
	
}

void APaishoPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	PollJoinTeam();
	PollClientServerTimeSync(DeltaSeconds);
	SetMatchGameTime(GetServerTime());
	PollHud();
}

void APaishoPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APaishoPlayerController, Team);
	DOREPLIFETIME(APaishoPlayerController, bIsWaitingForLevelUpInput);
	DOREPLIFETIME(APaishoPlayerController, LevelUpIndex);
}

void APaishoPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	Hero = Cast<APaishoHero>(InPawn);
	check(Hero != nullptr); // currently the player can only possess a hero
}

TObjectPtr<APaishoHero> APaishoPlayerController::GetHero()
{
	Hero = Hero == nullptr ? Cast<APaishoHero>(GetPawn()) : Hero;
	return Hero;
}

void APaishoPlayerController::PollJoinTeam()
{
	if(HasAuthority() && Team == nullptr)
	{
		if(APaishoGameState* GS = Cast<APaishoGameState>(GetWorld()->GetGameState()))
		{
			Team = GS->JoinTeam(this);
		}
	}
}

void APaishoPlayerController::OnRep_Team()
{
	if(Team)
	{
		//Team->BindUIToPlayer(this);
	}
}

void APaishoPlayerController::AuthInitiateLevelUp(int Level)
{
	/* Let the server player pause the game on level up */
	if(HasAuthority() && IsLocalController())
	{
		SetPause(true);
	}
	/* Replicated to all clients */
	bIsWaitingForLevelUpInput = true;
	
	check(Hero);
	TArray<FWeaponLevelUpInfo> WeaponLevelUpInfos = Hero->Arsenal->CalcWeaponLevelUpInfos(3); // get 3 options for now
	TArray<FElementLevelUpInfo> ElementLevelUpInfos = Hero->GetElementalKnowledgeComponent()->CalcElementLevelUpInfos(6); // all options for now	
	/* Tell each client to start the level up for their local player */

	if(Level % 2 == 0)
	{
		ClientInitiateLevelUp(WeaponLevelUpInfos);
	} else
	{
		ClientInitiateElementLevelUp(ElementLevelUpInfos);
	}
	
}

void APaishoPlayerController::AuthCompleteLevelUp()
{
	ClientCompleteLevelUp();
}

void APaishoPlayerController::ClientCompleteLevelUp_Implementation()
{
	if(IsLocalController() && LevelUpMenu)
	{
		LevelUpMenu->DeactivateWidget();
	}
}

void APaishoPlayerController::ClientInitiateLevelUp_Implementation(const TArray<FWeaponLevelUpInfo>& LevelUpInfos)
{
	if(IsLocalController())
	{
		UCommonActivatableWidget* Widget = PushWidgetToLayerStack(EWidgetLayer::Game, LevelUpMenuClass);
		if(ULevelUpSelectorWidget* LevelUpSelector = Cast<ULevelUpSelectorWidget>(Widget))
		{
			LevelUpMenu = LevelUpSelector;
			LevelUpMenu->Init(LevelUpInfos);
		} ELSE_ERROR("LevelUpSelector cast failed and won't be init.")
	} ELSE_ERROR("Client RPC on non-local player controller. I don't think this should be possible");
}

void APaishoPlayerController::ClientInitiateElementLevelUp_Implementation(
	const TArray<FElementLevelUpInfo>& LevelUpInfos)
{
	if(IsLocalController())
	{
		UCommonActivatableWidget* Widget = PushWidgetToLayerStack(EWidgetLayer::Game, LevelUpMenuClass);
		if(ULevelUpSelectorWidget* LevelUpSelector = Cast<ULevelUpSelectorWidget>(Widget))
		{
			LevelUpMenu = LevelUpSelector;
			LevelUpMenu->Init(LevelUpInfos);
		} ELSE_ERROR("LevelUpSelector cast failed and won't be init.")
	} ELSE_ERROR("Client RPC on non-local player controller. I don't think this should be possible");
}

void APaishoPlayerController::ServerCompleteLevelUp_Implementation(const int32 Index)
{
	bIsWaitingForLevelUpInput = false;
	LevelUpIndex = Index;
}

void APaishoPlayerController::PollClientServerTimeSync(const float DeltaSeconds)
{
	TimeSinceLastSync += DeltaSeconds;
	if(IsLocalController() && TimeSinceLastSync > TimeSyncFrequency)
	{
		ServerRequestServerTime(GetWorld()->GetTimeSeconds());
		TimeSinceLastSync = 0.0;
	}
}

float APaishoPlayerController::GetServerTime()
{
	if(HasAuthority()) { return GetWorld()->GetTimeSeconds(); }
	return GetWorld()->GetTimeSeconds() + ClientServerDelta;
}

void APaishoPlayerController::ReceivedPlayer()
{
	Super::ReceivedPlayer();
	if(IsLocalController())
	{
		ServerRequestServerTime(GetWorld()->GetTimeSeconds());
	}
}

void APaishoPlayerController::ServerRequestServerTime_Implementation(const float TimeOfClientRequest)
{
	const float ServerTimeOfReceipt = GetWorld()->GetTimeSeconds();
	ClientReportServerTime(TimeOfClientRequest, ServerTimeOfReceipt);
}

void APaishoPlayerController::ClientReportServerTime_Implementation(const float TimeOfClientRequest, const float TimeServerReceivedClientRequest)
{
	const float RoundTripTime = GetWorld()->GetTimeSeconds() - TimeOfClientRequest;
	const float CurrentServerTime = TimeServerReceivedClientRequest + (RoundTripTime * 0.5);
	ClientServerDelta = CurrentServerTime - GetWorld()->GetTimeSeconds();
}

void APaishoPlayerController::PollHud()
{
	if(IsLocalController() && PlayerHud)
	{
		PlayerHud->Poll(this);
	}
}

void APaishoPlayerController::BindHealthComponentToHud(const TObjectPtr<UHealthComponent> HealthComponent)
{
	if(IsLocalController() && PlayerHud)
	{
		PlayerHud->BindToHealthComponent(HealthComponent);
	}
}

void APaishoPlayerController::BindXpComponentToHud(const TObjectPtr<UXpComponent> XpComponent)
{
	if(IsLocalController() && PlayerHud)
	{
		PlayerHud->BindToXpComponent(XpComponent);
	}
}

// void APaishoPlayerController::BindTeamToHud(const TObjectPtr<APaishoTeam> InTeam)
// {
// 	if(IsLocalController() && PlayerHud)
// 	{
// 		//check(Team == InTeam); // we shouldn't bind to a team we're not on
// 		PlayerHud->BindToTeam(InTeam);
// 	}
// }

void APaishoPlayerController::SetMatchGameTime(const float GameTime)
{
	if(IsLocalController() && PlayerHud)
	{
		PlayerHud->SetMatchGameTime(GameTime);
	}
}
