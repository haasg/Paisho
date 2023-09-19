#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "StageData.generated.h"

struct FWaveData;

UCLASS()
class UStageData : public UDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly)
	TArray<FWaveData> Waves;
};
