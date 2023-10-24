#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Paisho/Weapons/WeaponLevelUpInfo.h"
#include "LevelUpSelector.generated.h"

class UHorizontalBox;
class ULevelUpCardButton;

UCLASS(Abstract)
class PAISHO_API ULevelUpSelector : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void Init(const TArray<FWeaponLevelUpInfo>& InWeaponLevelUpInfos);
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<ULevelUpCardButton>> LevelUpCardButtons;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ULevelUpCardButton> LevelUpCardButtonClass;
};
