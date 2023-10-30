#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Paisho/Data/LevelUpTypes.h"
#include "LevelUpSelectorWidget.generated.h"

class UHorizontalBox;
class ULevelUpCardButton;

UCLASS(Abstract)
class PAISHO_API ULevelUpSelectorWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void Init(const TArray<FWeaponLevelUpInfo>& InWeaponLevelUpInfos);

	void ButtonPressed(int32 Index);

	UPROPERTY(VisibleAnywhere)
	int32 SelectedIndex = -5;
	
protected:
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UHorizontalBox> CardBox;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<ULevelUpCardButton>> LevelUpCardButtons;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ULevelUpCardButton> LevelUpCardButtonClass;
};
