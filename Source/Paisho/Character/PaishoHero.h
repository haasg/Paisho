#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "PickupInterface.h"
#include "PaishoHero.generated.h"

class APaishoTeam;
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

public:
	APaishoHero();
	virtual void Tick(float DeltaSeconds) override;
    virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// TObjectPtr<APaishoPlayerController> GetPaishoController();
	// TObjectPtr<APaishoTeam> GetPaishoTeam();
	void PollInit();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<APaishoPlayerController> PaishoController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<APaishoTeam> Team;
	
public:
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

	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
	// TObjectPtr<UXpComponent> XpComponent;
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

	/* Called locally to propagate the movement intent to the server */
	UFUNCTION(BlueprintCallable)
	void LocalSetMovementIntent(const FVector& NewMovementIntent);

	UFUNCTION(Server, Reliable)
	void ServerSetMovementIntent(const FVector& NewMovementIntent);

	/* Updates the visual+arrow components to reflect the new movement intent */
	void UpdateMovementIntent(const FVector& NewMovementIntent);

	UFUNCTION()
	void OnRep_MovementIntent();
	
	UPROPERTY(ReplicatedUsing = OnRep_MovementIntent)
	FVector MovementIntent;
	
	FVector GetFacingDirection();
	FVector2d GetFacingDirection2d();
	float GetSpriteLeftRightDirection();
	/* End Visual+Movement Components */
	
};
