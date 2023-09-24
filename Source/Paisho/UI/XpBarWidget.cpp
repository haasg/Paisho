#include "XpBarWidget.h"

#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UXpBarWidget::Refresh(const float CurrentXp, const float MaxXp, const float XpPercent)
{
	const FText Text = FText::FromString(FString::Printf(TEXT("%d/%d"), FMath::RoundToInt(CurrentXp), FMath::RoundToInt(MaxXp)));
	XpText->SetText(Text);
	XpBar->SetPercent(XpPercent);
}
