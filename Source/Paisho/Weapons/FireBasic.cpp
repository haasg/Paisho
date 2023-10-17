#include "FireBasic.h"


AFireBasic::AFireBasic()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AFireBasic::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFireBasic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

