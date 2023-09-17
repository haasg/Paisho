#include "HealthBarWidget.h"

#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UHealthBarWidget::Refresh(const float CurrentHealth, const float MaxHealth, const float HealthPercent)
{
	const FText Text = FText::FromString(FString::Printf(TEXT("%d/%d"), FMath::RoundToInt(CurrentHealth), FMath::RoundToInt(MaxHealth)));
	HealthText->SetText(Text);
	HealthBar->SetPercent(HealthPercent);
}
