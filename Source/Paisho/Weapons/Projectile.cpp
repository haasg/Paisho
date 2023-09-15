#include "Projectile.h"

#include "PaperSpriteComponent.h"

AProjectile::AProjectile()
{
	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	RootComponent = SpriteComponent;
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	SpriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}


