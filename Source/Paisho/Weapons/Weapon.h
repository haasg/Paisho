#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

class UWeaponData;

UCLASS()
class AWeapon : public AActor
{
	GENERATED_BODY()
	
public:
	AWeapon();

	void Poll(float DeltaSeconds);
	virtual void Fire();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UWeaponData* WeaponData;

	UPROPERTY(VisibleAnywhere)
	float SecondsSinceLastFire = FLT_MAX;
	
};
