#pragma once

#include "PaperZDCharacter.h"
#include "PaishoVillain.generated.h"

class UVillainData;
class UHealthBarComponent;
class UHealthComponent;

UCLASS()
class PAISHO_API APaishoVillain : public APaperZDCharacter
{
	GENERATED_BODY()
	
public:
	APaishoVillain();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UVillainData> VillainData;

	/* Combat Components */
	UPROPERTY(EditAnywhere, Category = "Combat")
	UHealthComponent* Health;

	UPROPERTY(EditAnywhere, Category = "Combat")
	UHealthBarComponent* HealthBar;
	/* End Combat Components */
	
private:
	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
