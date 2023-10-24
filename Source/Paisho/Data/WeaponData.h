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
	
	float GetDamage(const int Level) const;
	float GetSpeed(const int Level) const;
	float GetLifetime(const int Level) const;
	float GetScale(const int Level) const;
	float GetMaxHits(const int Level) const;
	
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	TObjectPtr<UCurveTable> ProjectileCurveTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	FScalableFloat ProjectileDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	FScalableFloat ProjectileSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	FScalableFloat ProjectileLifetime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	FScalableFloat ProjectileScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	FScalableFloat ProjectileMaxHits;

	/* Level Up */
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "LevelUp")
	UTexture2D* WeaponIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "LevelUp")
	FText WeaponName;
	
};
