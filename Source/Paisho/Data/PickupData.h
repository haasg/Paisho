#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "PickupData.generated.h"

class APickup;

UCLASS()
class UPickupData : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPickupData();

	TSubclassOf<APickup> GetPickupClass() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<APickup> PickupClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Xp = 0;
};
