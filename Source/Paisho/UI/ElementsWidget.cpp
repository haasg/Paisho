#include "ElementsWidget.h"

#include "CommonTextBlock.h"
#include "Paisho/Character/ElementalKnowledgeComponent.h"

void UElementsWidget::SetElementLevel(const FElementalKnowledgeLevel& Knowledge)
{
	switch(Knowledge.Element) {
	case EElement::Water:
		WaterLevelText->SetText(FText::FromString(FString::FromInt(Knowledge.Level)));
		break;
	case EElement::Fire:
		FireLevelText->SetText(FText::FromString(FString::FromInt(Knowledge.Level)));
		break;
	case EElement::Nature:
		NatureLevelText->SetText(FText::FromString(FString::FromInt(Knowledge.Level)));
		break;
	case EElement::Earth:
		EarthLevelText->SetText(FText::FromString(FString::FromInt(Knowledge.Level)));
		break;
	case EElement::Light:
		LightLevelText->SetText(FText::FromString(FString::FromInt(Knowledge.Level)));
		break;
	case EElement::Void:
		VoidLevelText->SetText(FText::FromString(FString::FromInt(Knowledge.Level)));
		break;
	case EElement::Max:
		break;
	default: ;
	}

}
