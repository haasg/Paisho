#include "PaishoTeam.h"

#include "PaishoPlayerController.h"
#include "Paisho/Character/XpComponent.h"

APaishoTeam::APaishoTeam()
{
	PrimaryActorTick.bCanEverTick = true;
	XpComponent = CreateDefaultSubobject<UXpComponent>(TEXT("XpComponent"));
}

void APaishoTeam::BeginPlay()
{
	Super::BeginPlay();
	Tags.Add("AlphaTeam");
}

void APaishoTeam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APaishoTeam::Join(const TObjectPtr<APaishoPlayerController> PlayerController)
{
	
	checkf(PlayerController, TEXT("PlayerController is null"));
	
	Players.Add(PlayerController);
	PlayerController->BindXpComponentToHud(XpComponent);
	PlayerController->BindToLevelUp(XpComponent);
}

void APaishoTeam::CollectXp(const int32 Amount)
{
	XpComponent->CollectXp(Amount);
}

