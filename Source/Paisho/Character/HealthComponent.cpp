#include "HealthComponent.h"

#include "Net/UnrealNetwork.h"

UHealthComponent::UHealthComponent()
: MaxHealth(99)
, CurrentHealth(99)
{
}

void UHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UHealthComponent, CurrentHealth);
}

void UHealthComponent::Init(const float NewHealth, const float NewMaxHealth)
{
	CurrentHealth = NewHealth;
	MaxHealth = NewMaxHealth;
	OnHealthChanged.Broadcast();
}

void UHealthComponent::TakeDamage(const float DamageAmount)
{
	if(GetOwner() && GetOwner()->HasAuthority())
	{
		UpdateHealth(-DamageAmount);
	}
}

void UHealthComponent::Heal(const float HealAmount)
{
	if(GetOwner() && GetOwner()->HasAuthority())
	{
		UpdateHealth(HealAmount);
	}
}

void UHealthComponent::DebugMenuSetHealth(const float NewHealth)
{
	CurrentHealth = NewHealth;
	OnHealthChanged.Broadcast();
}

void UHealthComponent::UpdateHealth(const float HealthDelta)
{
	CurrentHealth += HealthDelta;
	if(CurrentHealth > MaxHealth)
	{
		CurrentHealth = MaxHealth;
	}
	OnHealthChanged.Broadcast();
	if(CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}
}

void UHealthComponent::OnRep_CurrentHealth()
{
	OnHealthChanged.Broadcast();
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
