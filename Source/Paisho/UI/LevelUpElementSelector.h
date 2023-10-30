#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Paisho/Data/LevelUpTypes.h"
#include "LevelUpElementSelector.generated.h"

class ULevelUpElementCardButton;

UCLASS(Abstract)
class PAISHO_API ULevelUpElementSelector : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void Init(const TArray<FElementLevelUpInfo>& InElementLevelUpInfos);
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<ULevelUpElementCardButton>> LevelUpCardButtons;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ULevelUpElementCardButton> LevelUpCardButtonClass;
};
