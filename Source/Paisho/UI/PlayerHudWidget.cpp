#include "PlayerHudWidget.h"

#include "ElementsWidget.h"
#include "GameTimeWidget.h"
#include "HealthBarWidget.h"
#include "XpBarWidget.h"
#include "Paisho/Character/HealthComponent.h"
#include "Paisho/Character/ElementalKnowledgeComponent.h"
#include "Paisho/Character/PaishoHero.h"
#include "Paisho/Framework/PaishoPlayerController.h"
#include "Paisho/Util/DebugUtil.h"

void UPlayerHudWidget::Poll(const TObjectPtr<APaishoPlayerController> LocalController)
{
	if(TObjectPtr<APaishoHero> Hero = LocalController->GetHero())
	{
		if(TObjectPtr<UElementalKnowledgeComponent> Knowledge = Hero->GetElementalKnowledgeComponent())
		{
			for(const auto& KnowledgeLevel : Knowledge->GetKnowledge())
			{
				ElementsWidget->SetElementLevel(KnowledgeLevel);
			}
		}
	}
}

void UPlayerHudWidget::BindToHealthComponent(const TObjectPtr<UHealthComponent> HealthComponent)
{
	HealthBarWidget->BindToHealthComponent(HealthComponent);
}

void UPlayerHudWidget::BindToXpComponent(const TObjectPtr<UXpComponent> XpComponent)
{
	XpBarWidget->BindToXpComponent(XpComponent);
}

// void UPlayerHudWidget::BindToTeam(const TObjectPtr<APaishoTeam> Team)
// {
// 	TeammatesBox->ClearChildren();
// 	
// 	for(const auto& Player : Team->GetPlayers())
// 	{
// 		if(!Player) continue; 
// 		if(const TObjectPtr<APaishoHero> Hero = Player->GetHero())
// 		{
// 			TObjectPtr<UTeammateWidget> TeammateWidget = CreateWidget<UTeammateWidget>(GetWorld(), TeammateWidgetClass);
// 			TeammateWidget->BindToHero(Hero);
// 			TeammatesBox->AddChild(TeammateWidget);
// 		}
// 	}
// }

void UPlayerHudWidget::SetMatchGameTime(const int32 GameTime)
{
	GameTimeWidget->Refresh(GameTime);
}

void UPlayerHudWidget::RefreshGameTime(const int32 GameTime)
{
	GameTimeWidget->Refresh(GameTime);
}

