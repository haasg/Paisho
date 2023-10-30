#include "LevelUpElementCardButton.h"

#include "CommonTextBlock.h"
#include "Components/Image.h"
#include "Paisho/Data/ElementData.h"

void ULevelUpElementCardButton::SetElementLevelUpInfo(const FElementLevelUpInfo& InElementLevelUpInfo)
{
    ElementLevelUpInfo = InElementLevelUpInfo;
	Refresh();
}

void ULevelUpElementCardButton::Refresh()
{
	if(ElementLevelUpInfo.ElementData)
	{
		ElementImage->SetBrushFromTexture(ElementLevelUpInfo.ElementData->Icon);
		ElementNameText->SetText(ElementLevelUpInfo.ElementData->Name);
		ElementLevelText->SetText(FText::AsNumber(ElementLevelUpInfo.CurrentLevel));
	}
}

