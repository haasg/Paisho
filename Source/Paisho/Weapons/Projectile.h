#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"


class UProjectileMovementComponent;
class UPaperSpriteComponent;

UCLASS()
class AProjectile : public AActor
{
	GENERATED_BODY()
public:

	AProjectile();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UProjectileMovementComponent* MovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperSpriteComponent* SpriteComponent;
	
};
