#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "PickupInterface.generated.h"

class UPickupData;
class APickup;

UENUM(BlueprintType)
enum class EPickupType : uint8
{
	None,
	Health,
	Xp,
	Max
};

UINTERFACE(BlueprintType, NotBlueprintable)
class UPickupInterface : public UInterface
{
	GENERATED_BODY()
};

class IPickupInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void OnPickup(UPickupData* PickupData) = 0;
	
};

