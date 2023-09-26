#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthChangedEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathEvent);

UCLASS()
class UHealthComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UHealthComponent();
	void Init(float NewHealth, float NewMaxHealth);

	void TakeDamage(float DamageAmount);

	UFUNCTION(BlueprintCallable)
	float CalcHealthPercent();

	UFUNCTION(BlueprintCallable) 
	float GetCurrentHealth();
	
	UFUNCTION(BlueprintCallable)
	float GetMaxHealth();

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnHealthChangedEvent OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnDeathEvent OnDeath;

	
	UFUNCTION(BlueprintCallable)
	void DebugMenuSetHealth(float NewHealth);




private:
	void UpdateHealth(float HealthDelta);
	
	UPROPERTY(VisibleAnywhere)
	float CurrentHealth;

	UPROPERTY(VisibleAnywhere)
	float MaxHealth;
	
	
};
