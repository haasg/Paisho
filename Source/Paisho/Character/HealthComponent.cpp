#include "HealthComponent.h"

UHealthComponent::UHealthComponent(): Health(0), MaxHealth(0)
{
}

void UHealthComponent::Init(const float NewHealth, const float NewMaxHealth)
{
	Health = NewHealth;
	MaxHealth = NewMaxHealth;
}

float UHealthComponent::CalcHealthPercent()
{
	check(MaxHealth != 0.f);
	return Health / MaxHealth;
}
