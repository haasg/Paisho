#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "PickupData.generated.h"


class UPaperSprite;

UCLASS()
class UPickupData : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPickupData();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperSprite> Sprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Xp = 0;
};
