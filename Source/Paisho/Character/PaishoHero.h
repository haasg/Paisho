#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "PaishoHero.generated.h"

class UHealthBarComponent;
class UHealthComponent;
class UStartingKit;
class UHeroData;
class UPaperFlipbook;
class UArsenalComponent;
class UCameraComponent;
class USpringArmComponent;
class AWeapon;

UCLASS()
class PAISHO_API APaishoHero : public APaperZDCharacter
{
	GENERATED_BODY()

	APaishoHero();
	static APaishoHero* FromData(UHeroData* HeroData, UWorld* World);

    virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UHeroData* HeroData;

	/* Camera Components */
	UPROPERTY(EditAnywhere, Category = "Camera")
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* Camera;
	/* End Camera Components */

	
	/* Combat Components */
	UPROPERTY(EditAnywhere, Category = "Combat")
	UHealthComponent* Health;

	//UPROPERTY(EditAnywhere, Category = "Combat")
	//UHealthBarComponent* HealthBar;
	
	UPROPERTY(EditAnywhere, Category = "Combat")
	UStartingKit* StartingKit;
	
	UPROPERTY(EditAnywhere, Category = "Combat")
	UArsenalComponent* Arsenal;

	/* End Combat Components */

	/* Visual Components */
	UPROPERTY(EditAnywhere, Category = "Visual")
	UPaperFlipbook* IdleAnimation;

	UPROPERTY(EditAnywhere, Category = "Visual")
	UPaperFlipbook* WalkAnimation;
	/* End Visual Components */
	
};
