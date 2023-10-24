#pragma once

#include "CoreMinimal.h"

#include "WeaponLevelUpInfo.generated.h"

class UWeaponData;

USTRUCT(BlueprintType)
struct PAISHO_API FWeaponLevelUpInfo
{
	GENERATED_BODY()

	UPROPERTY()
	TObjectPtr<UWeaponData> WeaponData;

	UPROPERTY()
	int32 CurrentLevel;
};
