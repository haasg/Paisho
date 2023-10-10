#include "PaishoGameState.h"

#include "GameFramework/PlayerState.h"
#include "Paisho/Mission/Stage.h"
#include "Paisho/Util/DebugUtil.h"

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
