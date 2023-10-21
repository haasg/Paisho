#pragma once

#include "CoreMinimal.h"
#include "WeaponFireType.h"
#include "ScalableFloat.h"
#include "Engine/DataAsset.h"
#include "WeaponData.generated.h"

class AProjectile;
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
	float GetDamage() const;
	TObjectPtr<UPaperSprite> GetProjectileSprite() const;

	TSubclassOf<AProjectile> GetProjectileClass() { return ProjectileClass; }

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AWeapon> WeaponClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireRate")
	FWeaponFireType FireType;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AProjectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile")
	TObjectPtr<UPaperSprite> ProjectileSprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCurveTable> ProjectileCurveTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FScalableFloat ProjectileDamage2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile")
	float ProjectileSpeed = 1000.0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile")
	float ProjectileDamage = 1.0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile")
	float ProjectileLifeTime = 5.0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile")
	float ProjectileScale = 1.0;
	
};
