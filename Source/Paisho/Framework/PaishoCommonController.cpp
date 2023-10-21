#include "PaishoCommonController.h"

#include "Blueprint/UserWidget.h"
#include "Paisho/UI/BaseWidget.h"

APaishoCommonController::APaishoCommonController()
{
}

void APaishoCommonController::BeginPlay()
{
	if(IsLocalPlayerController())
	{
		BaseWidget = CreateWidget<UBaseWidget>(this, BaseWidgetClass);
		BaseWidget->AddToViewport();	
	}

	/* Base UI needs to be created before anything else happens */
	Super::BeginPlay();
}
