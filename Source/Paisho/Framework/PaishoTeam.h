#pragma once

#include "CoreMinimal.h"
#include "Paisho/Data/TeamType.h"
#include "PaishoTeam.generated.h"

class APaishoPlayerController;
class UXpComponent;

UCLASS(Abstract)
class PAISHO_API APaishoTeam : public AActor
{
	GENERATED_BODY()

	/* Framework */
public:
	APaishoTeam();
	virtual void Tick(float DeltaTime) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
protected:
	virtual void BeginPlay() override;


	
	/* Team */
protected:
	UPROPERTY(VisibleAnywhere)
	ETeam TeamId = ETeam::RedTeam;



	/* Players */
public:
	void Join(TObjectPtr<APaishoPlayerController> PlayerController);
	TArray<TObjectPtr<APaishoPlayerController>> GetPlayers() const { return Players; }
protected:
	UFUNCTION()
	void OnRep_Players();

	UPROPERTY(ReplicatedUsing = OnRep_Players, VisibleAnywhere)
	TArray<TObjectPtr<APaishoPlayerController>> Players;


	
	/* Xp */
public:
	void CollectXp(int32 Amount);
	//void BindUIToPlayer(TObjectPtr<APaishoPlayerController> PlayerController);
protected:
	void PollForUnpause();

	UFUNCTION()
	void HandleLevelUp(int Level);
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UXpComponent> XpComponent;


};
