#include "HealthBarComponent.h"

UHealthBarComponent::UHealthBarComponent(): HealthComponent(nullptr)
{
}

void UHealthBarComponent::Init(UHealthComponent* NewHealthComponent)
{
	HealthComponent = NewHealthComponent;
}
