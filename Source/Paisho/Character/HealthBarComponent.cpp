#include "HealthBarComponent.h"

#include "HealthComponent.h"
#include "Paisho/UI/HealthBarWidget.h"

UHealthBarComponent::UHealthBarComponent() : HealthComponent(nullptr)
{
}

void UHealthBarComponent::Init(const TObjectPtr<UHealthComponent> NewHealthComponent)
{
	check(NewHealthComponent);
	HealthComponent = NewHealthComponent;
	NewHealthComponent->OnHealthChanged.AddDynamic(this, &ThisClass::Refresh);
	Refresh();
}

void UHealthBarComponent::Refresh()
{
	if(HealthComponent.IsValid())
	{
		if(UHealthBarWidget* HealthBarWidget = Cast<UHealthBarWidget>(GetWidget()))
		{
			const float CurrentHealth = HealthComponent->GetCurrentHealth();
			const float MaxHealth = HealthComponent->GetMaxHealth();
			const float HealthPercent = HealthComponent->CalcHealthPercent();
			
			HealthBarWidget->Refresh(CurrentHealth, MaxHealth, HealthPercent); 
		}
	}
}
