#pragma once

#include "CoreMinimal.h"

#include "LevelUpTypes.generated.h"

class UElementData;
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

USTRUCT(BlueprintType)
struct FElementLevelUpInfo
{
	GENERATED_BODY()

	UPROPERTY()
	TObjectPtr<UElementData> ElementData;

	UPROPERTY()
	int32 CurrentLevel;
};
