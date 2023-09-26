#include "PlayerHudWidget.h"

#include "GameTimeWidget.h"
#include "HealthBarWidget.h"
#include "XpBarWidget.h"
#include "Paisho/Character/HealthComponent.h"

void UPlayerHudWidget::BindToHealthComponent(const TObjectPtr<UHealthComponent> HealthComponent)
{
	HealthBarWidget->BindToHealthComponent(HealthComponent);
}

void UPlayerHudWidget::BindToXpComponent(const TObjectPtr<UXpComponent> XpComponent)
{
	XpBarWidget->BindToXpComponent(XpComponent);
}

void UPlayerHudWidget::RefreshGameTime(const int32 GameTime)
{
	GameTimeWidget->Refresh(GameTime);
}

