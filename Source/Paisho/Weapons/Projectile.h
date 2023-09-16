#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"


class UPaperSprite;
class UWeaponData;
class UProjectileMovementComponent;
class UPaperSpriteComponent;

UCLASS()
class AProjectile : public AActor
{
	GENERATED_BODY()
public:

	AProjectile();

	virtual void BeginPlay() override;

	/* Save yourself the headache and use this API */
	void SetSprite(UPaperSprite* Sprite);
	void SetRotation(const FRotator& Rotation);
	void SetLocation(const FVector& Location);
	void SetVelocity(const FVector& Velocity);
	void SetDirection(const FVector& Direction);
	void SetSpeed(float Speed);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SceneComponent;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UProjectileMovementComponent* MovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperSpriteComponent* SpriteComponent;

	// UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// UWeaponData* WeaponData;
	
};
