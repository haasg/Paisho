#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WeaponData.generated.h"



UCLASS()
class PAISHO_API UWeaponData : public UPrimaryDataAsset
{
	GENERATED_BODY()


	UPROPERTY(EditDefaultsOnly, Category = "FireRate")
	float RoundsPerMinute = 60.0;

	UPROPERTY(EditDefaultsOnly, Category = "FireRate")
	EFireType FireType;

	
	
};
