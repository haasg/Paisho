#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Stage.generated.h"

class UStageData;
class UWave;

UCLASS()
class PAISHO_API AStage : public AActor
{
	GENERATED_BODY()
	
public:
	AStage();

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStageData> StageData;
	
	TArray<TObjectPtr<UWave>> Waves;
	
};
