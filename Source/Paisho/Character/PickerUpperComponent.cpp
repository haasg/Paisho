#include "PickerUpperComponent.h"

#include "PickupInterface.h"
#include "Components/CapsuleComponent.h"
#include "Paisho/Util/DebugUtil.h"

UPickerUpperComponent::UPickerUpperComponent()
{
	PickerUpperCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("PickerUpperCapsule"));
	PickerUpperCapsule->SetCollisionProfileName(FName("PickerUpper"));
	PickerUpperCapsule->SetCapsuleHalfHeight(300.0);
	PickerUpperCapsule->SetCapsuleRadius(200.0);
}

void UPickerUpperComponent::BeginPlay()
{
	Super::BeginPlay();

	PickerUpperCapsule->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform);

	if(GetOwner())
	{
		if(GetOwner()->HasAuthority())
		{
			PickerUpperCapsule->OnComponentBeginOverlap.AddDynamic(this, &UPickerUpperComponent::HandleOverlap);
		}
	}
	else
	{
		ERROR("PickerUpperComponent has no owner!");
	}
}


void UPickerUpperComponent::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const TObjectPtr<AActor> Owner = GetOwner();
	if (Owner && Owner->GetClass()->ImplementsInterface(UPickupInterface::StaticClass()))
	{
		if (IPickupInterface* PickupInterface = Cast<IPickupInterface>(Owner))
		{
			PickupInterface->OnPickup();
			OtherActor->Destroy();
		}
	}
}