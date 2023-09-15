#include "Projectile.h"

#include "PaperSpriteComponent.h"

AProjectile::AProjectile()
{
	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	const FRotator Rotator = FRotator(0.f, 0.f, -90.f);
	SpriteComponent->SetWorldRotation(Rotator);
	RootComponent = SpriteComponent;
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	SpriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}


