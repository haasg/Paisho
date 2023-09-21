#pragma once

#include "PaperZDCharacter.h"
#include "PaishoVillain.generated.h"

class UPickupData;
class UPaperSpriteComponent;
class UVillainData;
class UHealthBarComponent;
class UHealthComponent;

UCLASS()
class PAISHO_API APaishoVillain : public AActor
{
	GENERATED_BODY()
	
public:
	APaishoVillain();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UVillainData> VillainData;

	/* Combat Components */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	UHealthComponent* Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	UHealthBarComponent* HealthBar;
	/* End Combat Components */


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TObjectPtr<UPaperSpriteComponent> SpriteComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCapsuleComponent> CapsuleComponent;


	// Eventually this should be replaced with some sort of "Loot Table Component"
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPickupData> PickupData;

	
	
private:
	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnDeath();
};
