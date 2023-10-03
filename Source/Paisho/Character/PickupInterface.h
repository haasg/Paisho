#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "PickupInterface.generated.h"

class APickup;

UENUM(BlueprintType)
enum class EPickupType : uint8
{
	Health,
	Xp,
	Max
};

USTRUCT(BlueprintType)
struct FPickupAction
{
	GENERATED_BODY()
	
	UPROPERTY()
	EPickupType Type;

	UPROPERTY()
	float Value;
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
	virtual void OnPickup(FPickupAction Action) = 0;
	
};

