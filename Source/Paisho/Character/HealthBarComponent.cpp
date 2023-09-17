#include "HealthBarComponent.h"

#include "HealthComponent.h"

UHealthBarComponent::UHealthBarComponent(): HealthComponent(nullptr)
{
}

void UHealthBarComponent::Init(UHealthComponent* NewHealthComponent)
{
	HealthComponent = NewHealthComponent;
}

float UHealthBarComponent::CalcHealthPercent()
{
	return HealthComponent->CalcHealthPercent();
}
