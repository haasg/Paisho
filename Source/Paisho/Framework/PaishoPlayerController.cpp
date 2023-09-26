#include "PaishoPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Paisho/Character/HealthComponent.h"
#include "Paisho/UI/PlayerHudWidget.h"

APaishoPlayerController::APaishoPlayerController()
{
	PlayerHud = nullptr;
}

void APaishoPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if(IsLocalPlayerController())
	{
		PlayerHud = CreateWidget<UPlayerHudWidget>(this, PlayerHudClass);
		PlayerHud->AddToViewport();	
	}
	
}

void APaishoPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	
}

void APaishoPlayerController::BindHealthComponentToHud(const TObjectPtr<UHealthComponent> HealthComponent)
{
	PlayerHud->BindToHealthComponent(HealthComponent);
}

void APaishoPlayerController::BindXpComponentToHud(const TObjectPtr<UXpComponent> XpComponent)
{
	PlayerHud->BindToXpComponent(XpComponent);
}
