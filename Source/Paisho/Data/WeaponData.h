#pragma once

#include "CoreMinimal.h"
#include "WeaponFireType.h"
#include "Engine/DataAsset.h"
#include "WeaponData.generated.h"

class AWeapon;
class UPaperSprite;
class UPaperFlipbook;


UCLASS()
class PAISHO_API UWeaponData : public UPrimaryDataAsset
{
	GENERATED_BODY()

	
public:
	TSubclassOf<AWeapon> GetWeaponClass() const;
	
	float PrimaryRpm() const;
	float PrimarySecondsPerShot() const;
	float GetProjectileSpeed() const;
	UPaperSprite* GetProjectileSprite() const;
	

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AWeapon> WeaponClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireRate")
	FWeaponFireType FireType;
	


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile")
	UPaperSprite* ProjectileSprite;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile")
	float ProjectileSpeed = 1000.0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile")
	float ProjectileDamage = 10.0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile")
	float ProjectileLifeTime = 5.0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile")
	float ProjectileScale = 1.0;
	
};
