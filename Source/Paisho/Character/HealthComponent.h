#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "HealthComponent.generated.h"

UCLASS()
class UHealthComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UHealthComponent();
	void Init(float NewHealth, float NewMaxHealth);

	float CalcHealthPercent();

private:
	UPROPERTY(VisibleAnywhere)
	float Health;

	UPROPERTY(VisibleAnywhere)
	float MaxHealth;
};
