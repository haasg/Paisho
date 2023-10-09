#include "PaishoUIExtensions.h"

#include "Paisho/Framework/PaishoCommonController.h"

UCommonActivatableWidget* UPaishoUIExtensions::PushContentToLayer_ForPlayer(APlayerController* PlayerController,
                                                                            EWidgetLayer LayerName, TSubclassOf<UCommonActivatableWidget> WidgetClass)
{
	if(APaishoCommonController* CommonController = Cast<APaishoCommonController>(PlayerController))
	{
		return CommonController->PushWidgetToLayerStack(LayerName, WidgetClass);
	}

	return nullptr;
}
