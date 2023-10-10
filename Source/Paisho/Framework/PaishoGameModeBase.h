#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PaishoGameModeBase.generated.h"

class UStageData;
class AStage;

UCLASS()
class PAISHO_API APaishoGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<AStage> CurrentStage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStageData> StageData;
};
