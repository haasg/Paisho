#include "TeammateWidget.h"

#include "HealthBarWidget.h"
#include "Paisho/Character/PaishoHero.h"

void UTeammateWidget::BindToHero(const TObjectPtr<APaishoHero> Hero)
{
	HealthBarWidget->BindToHealthComponent(Hero->GetHealthComponent());
}
