#include "HealthBarWidget.h"

#include "Components/Image.h"
#include "Components/PanelSlot.h"
#include "Components/ProgressBar.h"
#include "Paisho/Character/HealthBarComponent.h"

void UHealthBarWidget::Init(UHealthBarComponent* NewHealthBarComponent)
{
	HealthBarComponent = NewHealthBarComponent;
	Refresh();
}

void UHealthBarWidget::Refresh()
{
	const float HealthPercent = HealthBarComponent->CalcHealthPercent();
	HealthBar->SetPercent(HealthPercent);
}
