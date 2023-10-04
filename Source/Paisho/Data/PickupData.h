#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Paisho/Character/PickupInterface.h"

#include "PickupData.generated.h"

class APickup;

UCLASS()
class UPickupData : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPickupData();

	TSubclassOf<APickup> GetPickupClass() const;
	EPickupType GetType() const;
	float GetValue() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<APickup> PickupClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPickupType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value;
};
