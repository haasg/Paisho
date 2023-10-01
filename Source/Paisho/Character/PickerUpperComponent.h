#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"

#include "PickerUpperComponent.generated.h"

class UCapsuleComponent;

UCLASS()
class UPickerUpperComponent : public USceneComponent
{
	GENERATED_BODY()
	
public:
	UPickerUpperComponent();

protected:
	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Pickup")
	TObjectPtr<UCapsuleComponent> PickerUpperCapsule;
	
};
