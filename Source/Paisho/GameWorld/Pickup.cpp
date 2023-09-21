#include "Pickup.h"

#include "PaperSpriteComponent.h"
#include "Components/CapsuleComponent.h"

APickup::APickup()
{
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->SetCollisionProfileName(FName("Pickup"));
	CapsuleComponent->SetCapsuleHalfHeight(500.f);
	CapsuleComponent->SetCapsuleRadius(50.f);
	SetRootComponent(CapsuleComponent);

	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	SpriteComponent->SetupAttachment(RootComponent);
}

void APickup::BeginPlay()
{
	Super::BeginPlay();
}
