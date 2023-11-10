#include "PaishoGameState.h"

#include "PaishoTeam.h"
#include "GameFramework/PlayerState.h"
#include "Net/UnrealNetwork.h"
#include "Paisho/Character/PaishoVillain.h"
#include "Paisho/Character/XpComponent.h"
#include "Paisho/Util/DebugUtil.h"

APaishoGameState::APaishoGameState()
{
	PrimaryActorTick.bCanEverTick = true;
	GameTime = 0;
	
}

void APaishoGameState::BeginPlay()
{
	Super::BeginPlay();
	if(HasAuthority())
	{
		Team = GetWorld()->SpawnActor<APaishoTeam>(TeamStateClass);	
	}
	
}

void APaishoGameState::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	/* REPLICATE THIS FROM GAMEMODE EVENTUALLY */
	GameTime += DeltaSeconds;
	//PRINT("THING: %d", thing);
	thing++;

	if(HasAuthority()) { ServerCachePlayerLocations(); }
}

void APaishoGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APaishoGameState, Team);
}

TObjectPtr<APaishoTeam> APaishoGameState::JoinTeam(TObjectPtr<APaishoPlayerController> Controller)
{
	if(Team == nullptr) { PRINT("THIS CLIENT HAS A NULL TEAM IN THE GAME STATE"); }
	if(Controller == nullptr || Team == nullptr) { return nullptr; }
	
	Team->Join(Controller);
	return Team;
}

void APaishoGameState::ServerCachePlayerLocations()
{
	PlayerLocations.Empty();
	for(const auto& PlayerState : PlayerArray)
	{
		if(IsValid(PlayerState))
		{
			PlayerLocations.Add(PlayerState->GetPawn()->GetActorLocation());
		}
	}
}



float APaishoGameState::GetGameTime()
{
	return GameTime;
}

TOptional<FVector> APaishoGameState::AuthGetClosestPlayerTo(const FVector& Location)
{
	if(HasAuthority())
	{
		TOptional<FVector> ClosestPlayerLocation = TOptional<FVector>();
		float ClosestDistanceSquared = FLT_MAX;
		for(const auto& PlayerLocation : PlayerLocations)
		{
			const float DistanceSquared = FVector::DistSquared(Location, PlayerLocation);
			if(DistanceSquared < ClosestDistanceSquared)
			{
				ClosestPlayerLocation = TOptional(PlayerLocation);
				ClosestDistanceSquared = DistanceSquared;
			}
		}
		return ClosestPlayerLocation;
	} 


    checkf(false, TEXT("AuthGetClosestPlayerTo called on client"));
	return TOptional<FVector>();
}

TOptional<FVector> APaishoGameState::ServerGetRandomPlayerLocation()
{
	if(HasAuthority())
	{
		if (PlayerLocations.Num() > 0)
		{
			const int32 RandomIndex = FMath::RandRange(0, PlayerLocations.Num() - 1);
			return TOptional(PlayerLocations[RandomIndex]);
		}
		return TOptional<FVector>();
	}
	
	checkf(false, TEXT("ServerGetRandomPlayerLocation called on client"));
	return TOptional<FVector>();
}


FText APaishoGameState::GetGameTimeText()
{
	const int32 Minutes = static_cast<int32>(GameTime / 60.0f);
	const int32 Seconds = static_cast<int32>(FMath::Fmod(GameTime, 60.0f));
	
	const FString TimeString = FString::Printf(TEXT("%02d:%02d"), Minutes, Seconds);
	return FText::FromString(TimeString);
}


void APaishoGameState::RegisterVillain(const TObjectPtr<APaishoVillain> Villain)
{
	AliveVillains.Add(Villain);
}

void APaishoGameState::UnregisterVillain(const TObjectPtr<APaishoVillain> Villain)
{
	AliveVillains.Remove(Villain);
}

TObjectPtr<APaishoVillain> APaishoGameState::GetRandomVillain()
{
	if (AliveVillains.Num() > 0)
	{
		const int32 RandomIndex = FMath::RandRange(0, AliveVillains.Num() - 1);
		return AliveVillains[RandomIndex];
	}
	return nullptr;
}

TObjectPtr<APaishoVillain> APaishoGameState::GetClosestVillainTo(const FVector& ToLocation)
{
	TObjectPtr<APaishoVillain> ClosestVillain = nullptr;
	float ClosestDistanceSquared = FLT_MAX;
	for(const auto& Villain : AliveVillains)
	{
		if(IsValid(Villain))
		{
			const FVector VillainLocation = Villain->GetActorLocation();
			const float DistanceSquared = FVector::DistSquared(ToLocation, VillainLocation);
			if(DistanceSquared < ClosestDistanceSquared)
			{
				ClosestVillain = Villain;
				ClosestDistanceSquared = DistanceSquared;
			}
		}
	}
	return ClosestVillain;
}
