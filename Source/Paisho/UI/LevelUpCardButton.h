﻿#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Paisho/Weapons/WeaponLevelUpInfo.h"
#include "LevelUpCardButton.generated.h"


class UCommonTextBlock;
class UImage;
class UCommonActivatableWidget;

UCLASS(Abstract)
class PAISHO_API ULevelUpCardButton : public UCommonButtonBase
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	void SetWeaponLevelUpInfo(const FWeaponLevelUpInfo& InWeaponLevelUpInfo);
	void Refresh();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCommonActivatableWidget> ParentWidget;

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
