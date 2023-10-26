#include "PlayerHudWidget.h"

#include "GameTimeWidget.h"
#include "HealthBarWidget.h"
#include "XpBarWidget.h"
#include "TeammateWidget.h"
#include "Components/VerticalBox.h"
#include "Paisho/Character/HealthComponent.h"
#include "Paisho/Framework/PaishoPlayerController.h"
#include "Paisho/Framework/PaishoTeam.h"

void UPlayerHudWidget::BindToHealthComponent(const TObjectPtr<UHealthComponent> HealthComponent)
{
	HealthBarWidget->BindToHealthComponent(HealthComponent);
}

void UPlayerHudWidget::BindToXpComponent(const TObjectPtr<UXpComponent> XpComponent)
{
	XpBarWidget->BindToXpComponent(XpComponent);
}

void UPlayerHudWidget::BindToTeam(const TObjectPtr<APaishoTeam> Team)
{
	TeammatesBox->ClearChildren();
	
	for(const auto& Player : Team->GetPlayers())
	{
		if(const TObjectPtr<APaishoHero> Hero = Player->GetHero())
		{
			TObjectPtr<UTeammateWidget> TeammateWidget = CreateWidget<UTeammateWidget>(GetWorld(), TeammateWidgetClass);
			TeammateWidget->BindToHero(Hero);
			TeammatesBox->AddChild(TeammateWidget);
		}
	}
}

void UPlayerHudWidget::SetMatchGameTime(const int32 GameTime)
{
	GameTimeWidget->Refresh(GameTime);
}

void UPlayerHudWidget::RefreshGameTime(const int32 GameTime)
{
	GameTimeWidget->Refresh(GameTime);
}

