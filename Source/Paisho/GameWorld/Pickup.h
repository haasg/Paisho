#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Paisho/Character/PickupInterface.h"

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

	void PickedUpBy(TObjectPtr<AActor> PickedUpBy);



protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void ActivateTimeline();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCapsuleComponent> CapsuleComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperSpriteComponent> SpriteComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPickupData> PickupData;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<AActor> PickedUpByActor;
};
