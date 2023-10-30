#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Paisho/Data/LevelUpTypes.h"
#include "LevelUpSelectorWidget.generated.h"

class UHorizontalBox;
class ULevelUpCardButtonBase;

UCLASS(Abstract)
class PAISHO_API ULevelUpSelectorWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	void Init(const TArray<FWeaponLevelUpInfo>& InWeaponLevelUpInfos);
	void Init(const TArray<FElementLevelUpInfo>& InElementLevelUpInfos);

	void ButtonPressed(int32 Index);

	UPROPERTY(VisibleAnywhere)
	int32 SelectedIndex = -5;
	
protected:
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UHorizontalBox> CardBox;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<ULevelUpCardButtonBase>> LevelUpCardButtons;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ULevelUpCardButtonBase> LevelUpCardButtonClass;
};
