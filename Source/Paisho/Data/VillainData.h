#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "VillainData.generated.h"

class UPaperFlipbook;

UCLASS()
class PAISHO_API UVillainData : public UPrimaryDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	FText VillainName;

	UPROPERTY(EditDefaultsOnly)
	float StartingHealth = 10.0;

	UPROPERTY(EditDefaultsOnly)
	float MovementSpeed = 100.0;

	UPROPERTY(EditDefaultsOnly)
	UPaperFlipbook* WalkAnimation;
	
};
