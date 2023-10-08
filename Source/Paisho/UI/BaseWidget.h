#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"

#include "BaseWidget.generated.h"

class UCommonActivatableWidgetStack;

UCLASS()
class UBaseWidget : public UCommonUserWidget	
{
	GENERATED_BODY()
	
public:
	UBaseWidget();

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
