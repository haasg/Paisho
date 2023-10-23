#include "PaishoTeam.h"

#include "PaishoPlayerController.h"
#include "Net/UnrealNetwork.h"
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
			PlayerController->BindToLevelUp(XpComponent);
		}
	}
}

void APaishoTeam::BindUIToPlayer(const TObjectPtr<APaishoPlayerController> PlayerController)
{
	if(PlayerController->IsLocalController())
	{
		PlayerController->BindXpComponentToHud(XpComponent);
		PlayerController->BindToLevelUp(XpComponent);
	}
}

void APaishoTeam::CollectXp(const int32 Amount)
{
	XpComponent->CollectXp(Amount);
}

