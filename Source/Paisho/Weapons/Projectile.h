#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"


class UCapsuleComponent;
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
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/* Save yourself the headache and use this API */
	void SetWeaponData(UWeaponData* NewWeaponData) { WeaponData = NewWeaponData; UpdateProjectileFromData(); }
	void SetSprite(UPaperSprite* Sprite);
	void SetRotation(const FRotator& Rotation);
	void SetLocation(const FVector& Location);
	void SetVelocity(const FVector& Velocity);
	void SetDirection(const FVector& Direction);
	void SetSpeed(float Speed);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCapsuleComponent* CollisionCapsule;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperSpriteComponent* SpriteComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UProjectileMovementComponent* MovementComponent;
	
	UPROPERTY(VisibleAnywhere)
	float DamagePerHit;

	UPROPERTY(VisibleAnywhere)
	float CurrentPenetration;

protected:

	UFUNCTION(BlueprintImplementableEvent)
	void HitParticleFxEvent(float Damage);
	
	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void UpdateProjectileFromData();

	UFUNCTION()
	void OnRep_WeaponData();

	UPROPERTY(ReplicatedUsing = OnRep_WeaponData, VisibleAnywhere)
	UWeaponData* WeaponData;
	
};
