#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

class AProjectile;
class UWeaponData;

UCLASS()
class AWeapon : public AActor
{
	GENERATED_BODY()
	
public:
	AWeapon();

	void Poll(float DeltaSeconds);
	virtual void Fire() {};

	void SetWeaponData(UWeaponData* NewWeaponData) {WeaponData = NewWeaponData;}

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UWeaponData* WeaponData;

	UPROPERTY(VisibleAnywhere)
	int Level = 1;

	UPROPERTY(VisibleAnywhere)
	float SecondsSinceLastFire = FLT_MAX;
	
};
