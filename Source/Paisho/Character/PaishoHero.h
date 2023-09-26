#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "PaishoHero.generated.h"

class UXpComponent;
class UHealthBarWidget;
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
	TObjectPtr<UHeroData> HeroData;

	/* Camera Components */
	UPROPERTY(EditAnywhere, Category = "Camera")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(EditAnywhere, Category = "Camera")
	TObjectPtr<UCameraComponent> Camera;
	/* End Camera Components */

	/* Collision Components */
	
	/* This capsule sits at the center of the character and blocks movement.
	 * This is unlike the root component capsule that detects overlap events.
	 */
	UPROPERTY(EditAnywhere, Category = "Collision")
	TObjectPtr<UCapsuleComponent> HitboxCapsule;

	UPROPERTY(EditAnywhere, Category = "Pickup")
	TObjectPtr<UCapsuleComponent> PickerUpperCapsule;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
	TObjectPtr<UXpComponent> XpComponent;
	/* End Collision Components */

	
	/* Combat Components */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TObjectPtr<UHealthComponent> Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TObjectPtr<UHealthBarComponent> HealthBar;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TObjectPtr<UStartingKit> StartingKit;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TObjectPtr<UArsenalComponent> Arsenal;

	/* End Combat Components */

	/* Visual Components */
	UPROPERTY(EditAnywhere, Category = "Visual")
	TObjectPtr<UPaperFlipbook> IdleAnimation;

	UPROPERTY(EditAnywhere, Category = "Visual")
	TObjectPtr<UPaperFlipbook> WalkAnimation;
	/* End Visual Components */
	
};
