#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Paisho/Data/LevelUpTypes.h"
#include "LevelUpElementCardButton.generated.h"


class UImage;
class UCommonTextBlock;
class ULevelUpElementSelector;

UCLASS()
class PAISHO_API ULevelUpElementCardButton : public UCommonButtonBase
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	void SetElementLevelUpInfo(const FElementLevelUpInfo& InElementLevelUpInfo);
	void Refresh();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<ULevelUpElementSelector> ParentWidget;

protected:
	UPROPERTY(VisibleAnywhere)
	FElementLevelUpInfo ElementLevelUpInfo;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UCommonTextBlock* ElementNameText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UCommonTextBlock* ElementLevelText;
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UImage* ElementImage;
	
};
