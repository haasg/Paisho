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

	/* Lifetime */
public:
	APaishoHero();
	virtual void Tick(float DeltaSeconds) override;
    virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	void PollInit();


	
	/* Framework */
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<APaishoPlayerController> PaishoController;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UHeroData> HeroData;


	
	/* Camera */
public:
	UPROPERTY(EditAnywhere, Category = "Camera")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(EditAnywhere, Category = "Camera")
	TObjectPtr<UCameraComponent> Camera;

	

	/* Collision */
public:
	/* This capsule sits at the center of the character and blocks movement.
	 * This is unlike the root component capsule that detects overlap events.
	 */
	UPROPERTY(EditAnywhere, Category = "Collision")
	TObjectPtr<UCapsuleComponent> HitboxCapsule;


	
	/* Pickup */
public:
	UFUNCTION(BlueprintCallable)
	virtual void OnPickup(UPickupData* PickupData) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPickerUpperComponent> PickerUpperComponent;

	
	
	/* Health */
public:
	FORCEINLINE TObjectPtr<UHealthComponent> GetHealthComponent() const { return HealthComponent; }
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TObjectPtr<UHealthComponent> HealthComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TObjectPtr<UHealthBarComponent> HealthBarComponent;
	


	/* Arsenal */
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TObjectPtr<UArsenalComponent> Arsenal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TObjectPtr<UStartingKit> StartingKit;

	

	/* Animation */
public:
	UPROPERTY(EditAnywhere, Category = "Visual")
	TObjectPtr<UPaperFlipbook> IdleAnimation;

	UPROPERTY(EditAnywhere, Category = "Visual")
	TObjectPtr<UPaperFlipbook> WalkAnimation;

	

	/* Movement */
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UArrowComponent> FacingDirection2d; // where the character is "looking"

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UArrowComponent> SpriteDirectionLeftRight; // keeps a record of the last left-right direction the character moved in, useful for knowing things like if the player sprite is facing right or left even if they're just moving up
	
	UFUNCTION(BlueprintCallable)
	void LocalSetMovementIntent(const FVector& NewMovementIntent); // Called locally to propagate the movement intent to the server

	UFUNCTION(Server, Reliable)
	void ServerSetMovementIntent(const FVector& NewMovementIntent);
	
	void UpdateMovementIntent(const FVector& NewMovementIntent); // Updates the visual+arrow components to reflect the new movement intent
	
	UPROPERTY(ReplicatedUsing = OnRep_MovementIntent)
	FVector MovementIntent;
	
	UFUNCTION()
	void OnRep_MovementIntent();
	
	FVector GetFacingDirection();
	FVector2d GetFacingDirection2d();
	float GetSpriteLeftRightDirection();
	/* End Visual+Movement Components */
	
};
