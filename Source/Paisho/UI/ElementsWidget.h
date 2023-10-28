#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "ElementsWidget.generated.h"

class UCommonTextBlock;

UCLASS()
class PAISHO_API UElementsWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> WaterLevelText;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> FireLevelText;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> NatureLevelText;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> EarthLevelText;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> LightLevelText;
	
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> VoidLevelText;
};
