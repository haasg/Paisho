#include "WeaponLevelUpCardWidget.h"

#include "CommonTextBlock.h"
#include "Components/Image.h"
#include "Paisho/Data/WeaponData.h"

void UWeaponLevelUpCardWidget::SetWeaponLevelUpInfo(const FWeaponLevelUpInfo& InWeaponLevelUpInfo)
{
	WeaponLevelUpInfo = InWeaponLevelUpInfo;
	Refresh();
}

void UWeaponLevelUpCardWidget::Refresh()
{
	if(WeaponLevelUpInfo.WeaponData)
	{
		WeaponImage->SetBrushFromTexture(WeaponLevelUpInfo.WeaponData->WeaponIcon);
		WeaponNameText->SetText(WeaponLevelUpInfo.WeaponData->WeaponName);
		WeaponLevelText->SetText(FText::AsNumber(WeaponLevelUpInfo.CurrentLevel + 1));
	}
}

void UWeaponLevelUpCardWidget::Reset()
{
	SetColorAndOpacity(FLinearColor::White);
}
