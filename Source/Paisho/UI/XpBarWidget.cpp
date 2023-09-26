#include "XpBarWidget.h"

#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Paisho/Character/XpComponent.h"
#include "Paisho/Util/DebugUtil.h"

void UXpBarWidget::BindToXpComponent(const TObjectPtr<UXpComponent> NewXpComponent)
{
	XpComponent = NewXpComponent;
	NewXpComponent->OnXpChanged.AddDynamic(this, &ThisClass::Refresh);
}

void UXpBarWidget::Refresh()
{
	if(XpComponent.IsValid())
	{
		const float CurrentXp = XpComponent->CurrentXp();
		const float XpPercent = XpComponent->PercentThroughLevel();
		const FText Text = FText::FromString(FString::Printf(TEXT("%d"), FMath::RoundToInt(CurrentXp)));
		XpText->SetText(Text);
		XpBar->SetPercent(XpPercent);
	}
	else
	{
		ERROR("XpBarWidget refreshed without a valid XpComponent!");
	}
}


