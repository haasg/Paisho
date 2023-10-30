﻿#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Paisho/Data/LevelUpTypes.h"
#include "LevelUpCardButton.generated.h"


class ULevelUpSelector;
class UCommonTextBlock;
class UImage;
class UCommonActivatableWidget;

UCLASS(Abstract)
class PAISHO_API ULevelUpCardButton : public UCommonButtonBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetWeaponLevelUpInfo(const FWeaponLevelUpInfo& InWeaponLevelUpInfo);
	void Refresh();
	void Reset();

	UFUNCTION()
	void Pressed();

	virtual void NativeOnPressed() override;

	UPROPERTY()
	int32 Index;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<ULevelUpSelector> ParentWidget;

protected:
	
	
	UPROPERTY(VisibleAnywhere)
	FWeaponLevelUpInfo WeaponLevelUpInfo;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UCommonTextBlock* WeaponNameText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UImage* WeaponImage;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UCommonTextBlock* WeaponLevelText;
	
};
