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
	void RegisterVillain(TWeakObjectPtr<APaishoVillain> Villain);
	void UnregisterVillain(TWeakObjectPtr<APaishoVillain> Villain);
	TWeakObjectPtr<APaishoVillain> GetRandomVillain();
	TWeakObjectPtr<APaishoVillain> GetClosestVillainTo(const FVector& ToLocation);

protected:
	UPROPERTY(VisibleAnywhere)
	TArray<TWeakObjectPtr<APaishoVillain>> AliveVillains;
};
