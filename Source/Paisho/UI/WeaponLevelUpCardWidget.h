#pragma once

#include "CoreMinimal.h"
#include "LevelUpCardButtonBase.h"
#include "WeaponLevelUpCardWidget.generated.h"


UCLASS()
class PAISHO_API UWeaponLevelUpCardWidget : public ULevelUpCardButtonBase
{
	GENERATED_BODY()

public:
	void SetWeaponLevelUpInfo(const FWeaponLevelUpInfo& InWeaponLevelUpInfo);
	virtual void Refresh() override;
	virtual void Reset() override;
	
protected:
	UPROPERTY(VisibleAnywhere)
	FWeaponLevelUpInfo WeaponLevelUpInfo;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> WeaponNameText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UImage> WeaponImage;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> WeaponLevelText;
};
