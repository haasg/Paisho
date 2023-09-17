#include "HealthComponent.h"

UHealthComponent::UHealthComponent(): CurrentHealth(0), MaxHealth(0)
{
}

void UHealthComponent::Init(const float NewHealth, const float NewMaxHealth)
{
	CurrentHealth = NewHealth;
	MaxHealth = NewMaxHealth;
}

void UHealthComponent::TakeDamage(const float DamageAmount)
{
	UpdateHealth(-DamageAmount);
}

void UHealthComponent::UpdateHealth(const float HealthDelta)
{
	CurrentHealth += HealthDelta;
	OnHealthChanged.Broadcast();

	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}
}

float UHealthComponent::CalcHealthPercent()
{
	check(MaxHealth != 0.f);
	return CurrentHealth / MaxHealth;
}

float UHealthComponent::GetCurrentHealth()
{
	return CurrentHealth;
}

float UHealthComponent::GetMaxHealth()
{
	return MaxHealth;
}
