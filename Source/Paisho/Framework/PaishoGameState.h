#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "PaishoGameState.generated.h"


class APaishoPlayerController;
class APaishoTeam;
class UXpComponent;
class APaishoVillain;

UCLASS()
class PAISHO_API APaishoGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	APaishoGameState();
	virtual void Tick(float DeltaSeconds) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	TObjectPtr<APaishoTeam> JoinTeam(TObjectPtr<APaishoPlayerController> Controller);
	
protected:
	virtual void BeginPlay() override;

	/* could support multiple teams in the future */
	UPROPERTY(Replicated, VisibleAnywhere)
	TObjectPtr<APaishoTeam> Team;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<APaishoTeam> TeamStateClass;
	
public:
	UFUNCTION(BlueprintCallable)
	FText GetGameTimeText();

	float GetGameTime();

	/* Player Locations */
	TOptional<FVector> AuthGetClosestPlayerTo(const FVector& Location);
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

	int thing = 0;
};
