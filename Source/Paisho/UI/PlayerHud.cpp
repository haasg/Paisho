#include "PlayerHud.h"

#include "GameTimeWidget.h"
#include "HealthBarWidget.h"
#include "XpBarWidget.h"

void UPlayerHud::RefreshGameTime(const int32 GameTime)
{
	GameTimeWidget->Refresh(GameTime);
}

void UPlayerHud::RefreshHealth(const float CurrentHealth, const float MaxHealth, const float HealthPercent)
{
	HealthBar->Refresh(CurrentHealth, MaxHealth, HealthPercent);
}

void UPlayerHud::RefreshXp(const float CurrentXp, const float MaxXp, const float XpPercent)
{
	XpBar->Refresh(CurrentXp, MaxXp, XpPercent);
}

