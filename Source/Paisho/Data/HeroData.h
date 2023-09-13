#pragma once

#include "Engine/DataAsset.h"

#include "HeroData.generated.h"

class UPaperFlipbook;

UCLASS()
class UHeroData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly)
	FText HeroName;

	UPROPERTY(EditDefaultsOnly)
	float StartingHealth = 100.0;

	UPROPERTY(EditDefaultsOnly)
	float MovementSpeed = 300.0;

	UPROPERTY(EditDefaultsOnly)
	UPaperFlipbook* IdleAnimation;

	UPROPERTY(EditDefaultsOnly)
	UPaperFlipbook* WalkAnimation;
	
};
