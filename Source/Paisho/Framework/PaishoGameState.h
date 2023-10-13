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

	/* Player Locations */
	TOptional<FVector> ServerGetClosestPlayerTo(const FVector& Location);
	TOptional<FVector> ServerGetRandomPlayerLocation();
protected:
	void ServerCachePlayerLocations();

	UPROPERTY(VisibleAnywhere)
	TArray<FVector> PlayerLocations;

	
	/* Villains */
public:
	void RegisterVillain(TObjectPtr<APaishoVillain> Villain);
	void UnregisterVillain(TObjectPtr<APaishoVillain> Villain);
	TObjectPtr<APaishoVillain> GetRandomVillain();
	TObjectPtr<APaishoVillain> GetClosestVillainTo(const FVector& ToLocation);

protected:
	UPROPERTY(VisibleAnywhere)
	TArray<TObjectPtr<APaishoVillain>> AliveVillains;

	/* REPLICATE THIS FROM GAMEMODE EVENTUALLY */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float GameTime;

};
