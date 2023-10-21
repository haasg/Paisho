#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"

#include "BaseWidget.generated.h"

class UCommonActivatableWidgetStack;

UENUM(BlueprintType)
enum class EWidgetLayer : uint8
{
	Game,
	GameMenu,
	Menu,
	Prompt
};

UCLASS(Abstract)
class UBaseWidget : public UCommonUserWidget	
{
	GENERATED_BODY()
	
public:
	UBaseWidget();

	TObjectPtr<UCommonActivatableWidgetStack> GetLayerWidget(EWidgetLayer LayerName);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UCommonActivatableWidgetStack> GameStack;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UCommonActivatableWidgetStack> GameMenuStack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UCommonActivatableWidgetStack> MenuStack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UCommonActivatableWidgetStack> PromptStack;
	
};
