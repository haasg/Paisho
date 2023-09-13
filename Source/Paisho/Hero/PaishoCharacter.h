#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "PaishoCharacter.generated.h"

class UArsenalComponent;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class PAISHO_API APaishoCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

	APaishoCharacter();

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
