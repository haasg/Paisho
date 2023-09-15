#pragma once

#include "Engine/DataAsset.h"

#include "HeroData.generated.h"

class UPaperZDAnimInstance;
class UWeaponData;
class UPaperFlipbook;
class UWeaponData;

UCLASS()
class UHeroData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText HeroName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float StartingHealth = 100.0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MovementSpeed = 300.0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UPaperFlipbook* IdleAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UPaperFlipbook* WalkAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UPaperZDAnimInstance> AnimInstanceBP;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UWeaponData* StartingWeapon;
	
};
