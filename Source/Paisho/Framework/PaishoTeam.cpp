#include "PaishoTeam.h"

#include "PaishoPlayerController.h"
#include "Paisho/Character/XpComponent.h"
#include "Paisho/Util/DebugUtil.h"

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
	//PRINT("TEAM MEMBERS: %d, id: %d", Players.Num(), thing);
	thing++;
}

void APaishoTeam::Join(const TObjectPtr<APaishoPlayerController> PlayerController)
{

	if(PlayerController)
	{
		PRINT("JOINED TEAM");
		Players.Add(PlayerController);
		if(PlayerController->IsLocalController())
		{
			PRINT("LOCAL AND BINDING TO XP");
			PlayerController->BindXpComponentToHud(XpComponent);
			PlayerController->BindToLevelUp(XpComponent);
		}

	}

}

void APaishoTeam::CollectXp(const int32 Amount)
{
	XpComponent->CollectXp(Amount);
}

