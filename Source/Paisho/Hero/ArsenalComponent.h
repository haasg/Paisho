#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "ArsenalComponent.generated.h"

class AWeapon;

UCLASS()
class UArsenalComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UArsenalComponent() {}

	UPROPERTY(VisibleAnywhere)
	TArray<AWeapon*> Weapons;
};
