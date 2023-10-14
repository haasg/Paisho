#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "PickupInterface.h"
#include "PaishoHero.generated.h"

class UPickerUpperComponent;
class APaishoPlayerController;
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
class PAISHO_API APaishoHero : public APaperZDCharacter , public IPickupInterface
{
	GENERATED_BODY()

	APaishoHero();
	static APaishoHero* FromData(UHeroData* HeroData, UWorld* World);

    virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<APaishoPlayerController> PaishoController;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UHeroData> HeroData;

	/* Visual Components */
	UPROPERTY(EditAnywhere, Category = "Camera")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(EditAnywhere, Category = "Camera")
	TObjectPtr<UCameraComponent> Camera;
	/* End Visual Components */

	/* Collision Components */
	
	/* This capsule sits at the center of the character and blocks movement.
	 * This is unlike the root component capsule that detects overlap events.
	 */
	UPROPERTY(EditAnywhere, Category = "Collision")
	TObjectPtr<UCapsuleComponent> HitboxCapsule;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
	TObjectPtr<UXpComponent> XpComponent;
	/* End Collision Components */

	/* Pickup Components */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPickerUpperComponent> PickerUpperComponent;

	UFUNCTION(BlueprintCallable)
	virtual void OnPickup(UPickupData* PickupData) override;
	/* End Pickup Components */
	
	/* Combat Components */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TObjectPtr<UHealthComponent> HealthComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TObjectPtr<UHealthBarComponent> HealthBarComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TObjectPtr<UStartingKit> StartingKit;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TObjectPtr<UArsenalComponent> Arsenal;

	UFUNCTION()
	void HandleLevelUp(int NewLevel);
	/* End Combat Components */

	/* Visual+Movement Components */
	UPROPERTY(EditAnywhere, Category = "Visual")
	TObjectPtr<UPaperFlipbook> IdleAnimation;

	UPROPERTY(EditAnywhere, Category = "Visual")
	TObjectPtr<UPaperFlipbook> WalkAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UArrowComponent> FacingDirection2d; // where the character is "looking"

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UArrowComponent> SpriteDirectionLeftRight; // keeps a record of the last left-right direction the character moved in, useful for knowing things like if the player sprite is facing right or left even if they're just moving up

	FVector GetFacingDirection();
	FVector2d GetFacingDirection2d();
	float GetSpriteLeftRightDirection();
	/* End Visual+Movement Components */
	
};
