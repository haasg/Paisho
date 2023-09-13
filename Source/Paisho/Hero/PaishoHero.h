#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "PaishoHero.generated.h"

class UHeroData;
class UPaperFlipbook;
class UArsenalComponent;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class PAISHO_API APaishoHero : public APaperZDCharacter
{
	GENERATED_BODY()

	APaishoHero();
	static APaishoHero* FromData(UHeroData* HeroData, UWorld* World);

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere)
	UHeroData* HeroData;

	/* Camera Components */
	UPROPERTY(EditAnywhere, Category = "Camera")
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* Camera;
	/* End Camera Components */

	
	/* Combat Components */
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
