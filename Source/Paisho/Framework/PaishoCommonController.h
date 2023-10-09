#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "GameFramework/PlayerController.h"
#include "Paisho/UI/BaseWidget.h"
#include "Widgets/CommonActivatableWidgetContainer.h"

#include "PaishoCommonController.generated.h"

class UBaseWidget;



UCLASS()
class PAISHO_API APaishoCommonController : public APlayerController
{
	GENERATED_BODY()
public:
	APaishoCommonController();
	
	template <typename ActivatableWidgetT = UCommonActivatableWidget>
	ActivatableWidgetT* PushWidgetToLayerStack(EWidgetLayer LayerName, UClass* ActivatableWidgetClass)
	{
		return PushWidgetToLayerStack<ActivatableWidgetT>(LayerName, ActivatableWidgetClass, [](ActivatableWidgetT&) {});
	}

	template <typename ActivatableWidgetT = UCommonActivatableWidget>
	ActivatableWidgetT* PushWidgetToLayerStack(EWidgetLayer LayerName, UClass* ActivatableWidgetClass, TFunctionRef<void(ActivatableWidgetT&)> InitInstanceFunc)
	{
		static_assert(TIsDerivedFrom<ActivatableWidgetT, UCommonActivatableWidget>::IsDerived, "Only CommonActivatableWidgets can be used here");

	if (UCommonActivatableWidgetContainerBase* Layer = BaseWidget->GetLayerWidget(LayerName))
		{
			return Layer->AddWidget<ActivatableWidgetT>(ActivatableWidgetClass, InitInstanceFunc);
		}

		return nullptr;
	}

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBaseWidget> BaseWidget;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UBaseWidget> BaseWidgetClass;
};
