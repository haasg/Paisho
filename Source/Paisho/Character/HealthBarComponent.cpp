#include "HealthBarComponent.h"

#include "HealthComponent.h"
#include "Paisho/UI/HealthBarWidget.h"

UHealthBarComponent::UHealthBarComponent(): HealthComponent(nullptr)
{
}

void UHealthBarComponent::Init(UHealthComponent* NewHealthComponent)
{
	HealthComponent = NewHealthComponent;
}

void UHealthBarComponent::Refresh()
{
	UUserWidget* WidgetInside = GetWidget();
	if(UHealthBarWidget* HealthBarWidget = Cast<UHealthBarWidget>(WidgetInside))
	{
		HealthBarWidget->Refresh(); 
	}
}

float UHealthBarComponent::CalcHealthPercent()
{
	return HealthComponent->CalcHealthPercent();
}
