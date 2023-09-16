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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFireType FireType = EFireType::Auto;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PrimaryRpm = 60.0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "FireType == EFireType::Burst"))
	float BurstCount = 3.0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "FireType == EFireType::Burst"))
	float BurstRpm = 60.0;
};
