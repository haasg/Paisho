#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "PaishoGameState.generated.h"


class APaishoVillain;

UCLASS()
class PAISHO_API APaishoGameState : public AGameStateBase
{
	GENERATED_BODY()

public:

	APaishoGameState();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable)
	FText GetGameTimeText();

	float GetGameTime();
	// will need to account for all players eventually
	FVector GetPlayerLocation();
	
protected:
	/* REPLICATE THIS FROM GAMEMODE EVENTUALLY */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float GameTime;



public:
	void RegisterVillain(APaishoVillain* Villain);
	void UnregisterVillain(APaishoVillain* Villain);

protected:
	UPROPERTY(VisibleAnywhere)
	TArray<TObjectPtr<APaishoVillain>> AliveVillains;
};
