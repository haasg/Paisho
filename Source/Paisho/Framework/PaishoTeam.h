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

	/* Team */
protected:
	UPROPERTY(VisibleAnywhere)
	ETeam TeamId = ETeam::RedTeam;



	void Join(TObjectPtr<APaishoPlayerController> PlayerController);
	//void BindUIToPlayer(TObjectPtr<APaishoPlayerController> PlayerController);
	void CollectXp(int32 Amount);

	TArray<TObjectPtr<APaishoPlayerController>> GetPlayers() const { return Players; }

protected:
	virtual void BeginPlay() override;
	void PollForUnpause();

	UFUNCTION()
	void HandleLevelUp(int Level);
	
	

private:

	

	UFUNCTION()
	void OnRep_Players();

	UPROPERTY(ReplicatedUsing = OnRep_Players, VisibleAnywhere)
	TArray<TObjectPtr<APaishoPlayerController>> Players;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UXpComponent> XpComponent;
	
};
