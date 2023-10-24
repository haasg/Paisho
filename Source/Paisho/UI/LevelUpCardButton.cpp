#include "LevelUpCardButton.h"

#include "CommonTextBlock.h"
#include "Components/Image.h"
#include "Paisho/Data/WeaponData.h"

void ULevelUpCardButton::SetWeaponLevelUpInfo(const FWeaponLevelUpInfo& InWeaponLevelUpInfo)
{
	WeaponLevelUpInfo = InWeaponLevelUpInfo;
	Refresh();
}

void ULevelUpCardButton::Refresh()
{
	if(WeaponLevelUpInfo.WeaponData)
	{
		WeaponImage->SetBrushFromTexture(WeaponLevelUpInfo.WeaponData->WeaponIcon);
		WeaponNameText->SetText(WeaponLevelUpInfo.WeaponData->WeaponName);
		WeaponLevelText->SetText(FText::AsNumber(WeaponLevelUpInfo.CurrentLevel + 1));
	}
	
}
