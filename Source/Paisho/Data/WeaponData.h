#pragma once

#include "CoreMinimal.h"
#include "WeaponFireType.h"
#include "Engine/DataAsset.h"
#include "WeaponData.generated.h"

class UPaperFlipbook;


UCLASS()
class PAISHO_API UWeaponData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, Category = "FireRate")
	EFireType FireType;
	
	UPROPERTY(EditDefaultsOnly)
	float Damage = 10.0;

	UPROPERTY(EditDefaultsOnly)
	UPaperFlipbook* ProjectileAnimation;


	
	
};
