#pragma once

#include "CoreMinimal.h"

class UWeaponData;

USTRUCT()
struct PAISHO_API FWeaponLevelUpInfo
{
	GENERATED_BODY()

	UPROPERTY()
	TObjectPtr<UWeaponData> WeaponData;

	UPROPERTY()
	int32 CurrentLevel;
};
