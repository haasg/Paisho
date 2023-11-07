﻿#pragma once

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

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:

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
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
	void OnDeath();
};
