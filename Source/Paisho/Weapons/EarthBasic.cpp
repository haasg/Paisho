#include "EarthBasic.h"


AEarthBasic::AEarthBasic()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AEarthBasic::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEarthBasic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

