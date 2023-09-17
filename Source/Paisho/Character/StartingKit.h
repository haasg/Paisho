#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "StartingKit.generated.h"

class UWeaponData;

UCLASS()
class UStartingKit : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	TArray<UWeaponData*> Weapons;
};
