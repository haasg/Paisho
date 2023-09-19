#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "PaishoGameState.generated.h"

UCLASS()
class PAISHO_API APaishoGameState : public AGameStateBase
{
	GENERATED_BODY()

public:

	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable)
	float GetGameTime() { return GameTime; }
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float GameTime;
};
