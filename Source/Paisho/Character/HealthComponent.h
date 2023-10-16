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
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	void Init(float NewHealth, float NewMaxHealth);

	
	void TakeDamage(float DamageAmount);
	void Heal(float HealAmount);

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
	float MaxHealth;

	UFUNCTION()
	void OnRep_CurrentHealth();

	UPROPERTY(ReplicatedUsing = OnRep_CurrentHealth, VisibleAnywhere)
	float CurrentHealth;

	
	
};
