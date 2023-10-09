#include "PaishoCommonController.h"

#include "Blueprint/UserWidget.h"
#include "Paisho/UI/BaseWidget.h"

APaishoCommonController::APaishoCommonController()
{
}

void APaishoCommonController::BeginPlay()
{
	/* Base UI needs to be created before anything else happens */
	if(IsLocalPlayerController())
	{
		BaseWidget = CreateWidget<UBaseWidget>(this, BaseWidgetClass);
		BaseWidget->AddToViewport();	
	}
	
	Super::BeginPlay();
}
