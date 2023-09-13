#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "PaishoHero.generated.h"

class UArsenalComponent;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class PAISHO_API APaishoHero : public APaperZDCharacter
{
	GENERATED_BODY()

	APaishoHero();

	virtual void Tick(float DeltaSeconds) override;

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
	
};
