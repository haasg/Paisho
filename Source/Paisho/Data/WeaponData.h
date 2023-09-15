#pragma once

#include "CoreMinimal.h"
#include "WeaponFireType.h"
#include "Engine/DataAsset.h"
#include "WeaponData.generated.h"

class UPaperSprite;
class UPaperFlipbook;


UCLASS()
class PAISHO_API UWeaponData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "FireRate")
	EFireType FireType;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Damage = 10.0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UPaperSprite* ProjectileSprite;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UPaperFlipbook* ProjectileAnimation;


	
	
};
