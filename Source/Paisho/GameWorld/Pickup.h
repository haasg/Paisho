#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Pickup.generated.h"

class UPickupData;
class UPaperSpriteComponent;
class UCapsuleComponent;

UCLASS()
class APickup : public AActor
{
	GENERATED_BODY()
public:
	APickup();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCapsuleComponent> CapsuleComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperSpriteComponent> SpriteComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPickupData> PickupData;
};
