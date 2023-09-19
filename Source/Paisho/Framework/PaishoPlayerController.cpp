#include "PaishoPlayerController.h"

#include "Blueprint/UserWidget.h"

APaishoPlayerController::APaishoPlayerController()
{
	PlayerHud = nullptr;
}

void APaishoPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerHud = CreateWidget<UUserWidget>(this, PlayerHudClass);
	PlayerHud->AddToViewport();
}
