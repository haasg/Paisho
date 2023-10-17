#include "WaterBasic.h"


AWaterBasic::AWaterBasic()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AWaterBasic::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWaterBasic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

