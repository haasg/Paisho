#include "PlayerHudWidget.h"

#include "GameTimeWidget.h"
#include "HealthBarWidget.h"
#include "XpBarWidget.h"

void UPlayerHudWidget::RefreshGameTime(const int32 GameTime)
{
	GameTimeWidget->Refresh(GameTime);
}

void UPlayerHudWidget::RefreshHealth(const float CurrentHealth, const float MaxHealth, const float HealthPercent)
{
	HealthBarWidget->Refresh(CurrentHealth, MaxHealth, HealthPercent);
}

void UPlayerHudWidget::RefreshXp(const float CurrentXp, const float MaxXp, const float XpPercent)
{
	XpBarWidget->Refresh(CurrentXp, MaxXp, XpPercent);
}

