#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"


class UPaperSpriteComponent;

UCLASS()
class AProjectile : public AActor
{
	GENERATED_BODY()
public:

	AProjectile();

	virtual void BeginPlay() override;

	UPROPERTY()
	UPaperSpriteComponent* SpriteComponent;
	
};
