#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Stage.generated.h"

class UStageData;
class UWave;

UCLASS()
class PAISHO_API AStage : public AInfo
{
	GENERATED_BODY()
	
public:
	AStage();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	void Init(UStageData* NewStageData);

private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStageData> StageData;
	
	UPROPERTY(VisibleAnywhere)
	TArray<TObjectPtr<UWave>> Waves;
	
};
