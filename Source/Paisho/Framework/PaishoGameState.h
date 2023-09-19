#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "PaishoGameState.generated.h"

UCLASS()
class PAISHO_API APaishoGameState : public AGameStateBase
{
	GENERATED_BODY()

public:

	APaishoGameState();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable)
	FText GetGameTime();
	
protected:
	/* REPLICATE THIS FROM GAMEMODE EVENTUALLY */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float GameTime;
};
