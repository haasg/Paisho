#include "PickerUpperComponent.h"

#include "Components/CapsuleComponent.h"
#include "Paisho/Util/DebugUtil.h"

UPickerUpperComponent::UPickerUpperComponent()
{
	PickerUpperCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("PickerUpperCapsule"));
	PickerUpperCapsule->SetCollisionProfileName(FName("HeroPickerUpper"));
	PickerUpperCapsule->SetCapsuleHalfHeight(1000.0);
	PickerUpperCapsule->SetCapsuleRadius(200.0);
}

void UPickerUpperComponent::BeginPlay()
{
	Super::BeginPlay();

	PickerUpperCapsule->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform);

	//PickerUpperCapsule->OnComponentBeginOverlap.AddDynamic(this, &UPickerUpperComponent::HandleOverlap);
}


void UPickerUpperComponent::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PRINT("PICKER UPPER OVERLAP %s", *OtherActor->GetName());
}