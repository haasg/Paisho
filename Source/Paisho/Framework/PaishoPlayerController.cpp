#include "PaishoPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Paisho/Character/HealthComponent.h"
#include "Paisho/UI/PlayerHudWidget.h"
#include "PaishoCommonController.h"
#include "PaishoGameState.h"
#include "PaishoTeam.h"
#include "Net/UnrealNetwork.h"
#include "Paisho/Character/XpComponent.h"

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
	PollInit();
	PollClientServerTimeSync(DeltaSeconds);
	SetMatchGameTime(GetServerTime());
}

void APaishoPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APaishoPlayerController, Team);
}

void APaishoPlayerController::PollInit()
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
		Team->BindUIToPlayer(this);
	}
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

void APaishoPlayerController::SetMatchGameTime(const float GameTime)
{
	if(IsLocalController() && PlayerHud)
	{
		PlayerHud->SetMatchGameTime(GameTime);
	}
}

void APaishoPlayerController::BindToLevelUp(TObjectPtr<UXpComponent> XpComponent)
{
	if(IsLocalController())
	{
		XpComponent->OnLevelUp.AddDynamic(this, &ThisClass::ShowLevelUpMenu);
	}
}

void APaishoPlayerController::ShowLevelUpMenu(int NewLevel)
{
	if(IsLocalController())
	{
		PushWidgetToLayerStack(EWidgetLayer::Game, LevelUpMenuClass);
	}
}
