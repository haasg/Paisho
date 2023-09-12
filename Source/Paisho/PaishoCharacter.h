#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "PaishoCharacter.generated.h"

UCLASS()
class PAISHO_API APaishoCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

	APaishoCharacter();

	virtual void Tick(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere, Category = "Camera")
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, Category = "Camera")
	class UCameraComponent* Camera;
	
};
