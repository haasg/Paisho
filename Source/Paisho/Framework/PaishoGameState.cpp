#include "PaishoGameState.h"

#include "GameFramework/PlayerState.h"
#include "Paisho/Character/PaishoVillain.h"

APaishoGameState::APaishoGameState()
{
	PrimaryActorTick.bCanEverTick = true;
	GameTime = 0;
}

void APaishoGameState::BeginPlay()
{
	Super::BeginPlay();

}

void APaishoGameState::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	/* REPLICATE THIS FROM GAMEMODE EVENTUALLY */
	GameTime += DeltaSeconds;
}

float APaishoGameState::GetGameTime()
{
	return GameTime;
}

FVector APaishoGameState::GetPlayerLocation()
{
	// TODO: FIGURE THIS OUT
	if(HasAuthority())
	{
		return PlayerArray[0]->GetPawn()->GetActorLocation();
	}
	return FVector::ZeroVector;
}


FText APaishoGameState::GetGameTimeText()
{
	const int32 Minutes = static_cast<int32>(GameTime / 60.0f);
	const int32 Seconds = static_cast<int32>(FMath::Fmod(GameTime, 60.0f));
	
	const FString TimeString = FString::Printf(TEXT("%02d:%02d"), Minutes, Seconds);
	return FText::FromString(TimeString);
}


void APaishoGameState::RegisterVillain(const TWeakObjectPtr<APaishoVillain> Villain)
{
	AliveVillains.Add(Villain);
}

void APaishoGameState::UnregisterVillain(const TWeakObjectPtr<APaishoVillain> Villain)
{
	AliveVillains.Remove(Villain);
}

TWeakObjectPtr<APaishoVillain> APaishoGameState::GetRandomVillain()
{
	if (AliveVillains.Num() > 0)
	{
		const int32 RandomIndex = FMath::RandRange(0, AliveVillains.Num() - 1);
		return AliveVillains[RandomIndex];
	}
	return nullptr;
}

TWeakObjectPtr<APaishoVillain> APaishoGameState::GetClosestVillainTo(const FVector& ToLocation)
{
	TWeakObjectPtr<APaishoVillain> ClosestVillain = nullptr;
	float ClosestDistanceSquared = FLT_MAX;
	for(const auto& Villain : AliveVillains)
	{
		if(Villain.IsValid())
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
