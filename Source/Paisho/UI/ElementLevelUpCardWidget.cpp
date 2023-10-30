#include "ElementLevelUpCardWidget.h"

#include "CommonTextBlock.h"
#include "Components/Image.h"
#include "Paisho/Data/ElementData.h"

void UElementLevelUpCardWidget::SetElementLevelUpInfo(const FElementLevelUpInfo& InElementLevelUpInfo)
{
	ElementLevelUpInfo = InElementLevelUpInfo;
	Refresh();
}

void UElementLevelUpCardWidget::Refresh()
{
	if(ElementLevelUpInfo.ElementData)
	{
		ElementImage->SetBrushFromTexture(ElementLevelUpInfo.ElementData->Icon);
		ElementNameText->SetText(ElementLevelUpInfo.ElementData->Name);
		ElementLevelText->SetText(FText::AsNumber(ElementLevelUpInfo.CurrentLevel));
	}
}

void UElementLevelUpCardWidget::Reset()
{
	SetColorAndOpacity(FLinearColor::White);
}
