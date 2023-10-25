#include "PaishoTeam.h"

#include "PaishoPlayerController.h"
#include "Net/UnrealNetwork.h"
#include "Paisho/Character/XpComponent.h"
#include "Paisho/Util/DebugUtil.h"

APaishoTeam::APaishoTeam()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = true;
	XpComponent = CreateDefaultSubobject<UXpComponent>(TEXT("XpComponent"));
}

void APaishoTeam::BeginPlay()
{
	Super::BeginPlay();
	Tags.Add("AlphaTeam");
	
	if(HasAuthority())
	{
		XpComponent->OnLevelUp.AddDynamic(this, &APaishoTeam::HandleLevelUp);
	}
}

void APaishoTeam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PollForUnpause();
}

void APaishoTeam::PollForUnpause()
{
	if(HasAuthority() && Players.Num() > 0)
	{
		/* Get the server player controller - probably optimize this someday */
		APaishoPlayerController* AuthPlayer = nullptr;
		for(const auto& Player : Players)
		{
			if(Player->IsLocalController())
			{
				AuthPlayer = Player;
			}
		}
		/* We should have an auth player here since there is one team and everyone must join it. This will need to change to support multiple teams */
		/* Could just return but want to catch possible errors for now */
		check(AuthPlayer != nullptr); 

		/* If the game isn't paused we can return */
		if(!AuthPlayer->IsPaused()) return;
		
		bool bShouldStayPaused = false;
		for(const auto& Player : Players)
		{
			if(Player->bIsWaitingForLevelUpInput)
			{
				bShouldStayPaused = true;
				break;
			}
		}

		/* If all players are done we can unpause */
		if(!bShouldStayPaused)
		{
			AuthPlayer->SetPause(false);
			for(const auto& Player : Players)
			{
				Player->AuthCompleteLevelUp();
			}
		}
	}
}

void APaishoTeam::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APaishoTeam, Players);
}

void APaishoTeam::Join(const TObjectPtr<APaishoPlayerController> PlayerController)
{
	if(HasAuthority() && PlayerController)
	{
		Players.Add(PlayerController);
		if(PlayerController->IsLocalController())
		{
			PlayerController->BindXpComponentToHud(XpComponent);
			//PlayerController->BindToLevelUp(XpComponent);
		}
	}
}

void APaishoTeam::HandleLevelUp(int Level)
{
	if(HasAuthority())
	{
		for(auto& Player : Players)
		{
			Player->AuthInitiateLevelUp(Level);
		}
	}
}

void APaishoTeam::OnRep_Players()
{
	for(const auto& Player : Players)
	{
		Player->BindTeamToHud(this);	
	}
}

void APaishoTeam::BindUIToPlayer(const TObjectPtr<APaishoPlayerController> PlayerController)
{
	if(PlayerController->IsLocalController())
	{
		PlayerController->BindXpComponentToHud(XpComponent);
		// if(HasAuthority())
		// {
		// 	PlayerController->BindToLevelUp(XpComponent);
		// }
	}
}

void APaishoTeam::CollectXp(const int32 Amount)
{
	XpComponent->CollectXp(Amount);
}

