#pragma once

#include "CoreMinimal.h"
#include "PaishoTeam.generated.h"

class APaishoPlayerController;
class UXpComponent;

UCLASS(Abstract)
class PAISHO_API APaishoTeam : public AActor
{
	GENERATED_BODY()

public:
	APaishoTeam();
	virtual void Tick(float DeltaTime) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	void Join(TObjectPtr<APaishoPlayerController> PlayerController);
	void BindUIToPlayer(TObjectPtr<APaishoPlayerController> PlayerController);
	void CollectXp(int32 Amount);

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(Replicated, VisibleAnywhere)
	TArray<TObjectPtr<APaishoPlayerController>> Players;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UXpComponent> XpComponent;

	int thing = 0;
	
};
