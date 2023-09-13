#pragma once

#include "CoreMinimal.h"

#include "WeaponFireType.generated.h"

UENUM(BlueprintType)
enum class EFireType : uint8
{
	Auto,
	Burst
};

USTRUCT(BlueprintType)
struct FWeaponFireType
{
    GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	EFireType FireType;

	UPROPERTY(EditDefaultsOnly)
	float PrimaryRpm = 60.0;
	
	UPROPERTY(EditDefaultsOnly, meta = (EditCondition = "Type == EFireType::Burst"))
	float BurstCount = 3.0;
	
	UPROPERTY(EditDefaultsOnly, meta = (EditCondition = "Type == EFireType::Burst"))
	float BurstRpm = 60.0;
};
