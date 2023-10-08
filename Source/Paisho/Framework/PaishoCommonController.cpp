#include "PaishoCommonController.h"

#include "Blueprint/UserWidget.h"
#include "Paisho/UI/BaseWidget.h"

APaishoCommonController::APaishoCommonController()
{
}

void APaishoCommonController::BeginPlay()
{
	Super::BeginPlay();

	if(IsLocalPlayerController())
	{
		BaseWidget = CreateWidget<UBaseWidget>(this, BaseWidgetClass);
		BaseWidget->AddToViewport();	
	}
}
