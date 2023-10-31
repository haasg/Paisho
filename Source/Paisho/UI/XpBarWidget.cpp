#include "XpBarWidget.h"

#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Paisho/Character/XpComponent.h"
#include "Paisho/Util/DebugUtil.h"

void UXpBarWidget::BindToXpComponent(const TObjectPtr<UXpComponent> NewXpComponent)
{
	XpComponent = NewXpComponent;
	NewXpComponent->OnXpChanged.AddDynamic(this, &ThisClass::Refresh);
	Refresh();
}

void UXpBarWidget::Refresh()
{
	if(XpComponent.IsValid())
	{
		const int CurrentLevel = XpComponent->CurrentLevel();
		const float XpSinceLevelUp = XpComponent->XpSinceLevelUp();
		const float XpToCompleteCurrentLevel = XpComponent->TotalXpRequiredToCompleteCurrentLevel();
		const float XpPercent = XpComponent->PercentThroughLevel();

		const FText Text = FText::FromString(FString::Printf(TEXT("LEVEL: %d --- %d/%d"), CurrentLevel, FMath::RoundToInt(XpSinceLevelUp), FMath::RoundToInt(XpToCompleteCurrentLevel)));
		XpText->SetText(Text);
		XpBar->SetPercent(XpPercent);
	} ELSE_ERROR("XpBarWidget refreshed without a valid XpComponent!")
}


