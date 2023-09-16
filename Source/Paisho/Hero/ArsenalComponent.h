#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "ArsenalComponent.generated.h"

class UWeaponData;
class AWeapon;

UCLASS()
class UArsenalComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UArsenalComponent() {}

	void AddWeapon(UWeaponData* WeaponData);
	void Poll(float DeltaSeconds);

private:
	UPROPERTY(VisibleAnywhere)
	TArray<AWeapon*> Weapons;
};
