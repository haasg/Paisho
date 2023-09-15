#include "Projectile.h"

#include "PaperSpriteComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

AProjectile::AProjectile()
{
	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	const FRotator Rotator = FRotator(0.f, 0.f, -90.f);
	SpriteComponent->SetWorldRotation(Rotator);
	RootComponent = SpriteComponent;

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));
	MovementComponent->Velocity = FVector(500.f, 0.f, 0.f);
	MovementComponent->MaxSpeed = 1000.f;
	MovementComponent->ProjectileGravityScale = 0.f;
	//MovementComponent->bRotationFollowsVelocity = true;
	MovementComponent->bShouldBounce = false;
	
	
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	SpriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}


