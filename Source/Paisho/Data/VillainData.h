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
	float StartingHealth;

	UPROPERTY(EditDefaultsOnly)
	float MovementSpeed;

	UPROPERTY(EditDefaultsOnly)
	UPaperFlipbook* WalkAnimation;
	
};
