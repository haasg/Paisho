#include "Projectile.h"

#include "PaperSpriteComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Paisho/Data/WeaponData.h"

AProjectile::AProjectile()
{
	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	const FRotator Rotator = FRotator(0.f, 0.f, -90.f);
	SpriteComponent->SetWorldRotation(Rotator);
	RootComponent = SpriteComponent;

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));
	MovementComponent->InitialSpeed = 1000.f;
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

void AProjectile::SetSprite(UPaperSprite* Sprite)
{
	SpriteComponent->SetSprite(Sprite);
}

void AProjectile::SetVelocity(const FVector& Velocity)
{
	MovementComponent->Velocity = Velocity;
}

void AProjectile::SetDirection(const FVector& Direction)
{
	const float Speed = MovementComponent->Velocity.Size();
	MovementComponent->Velocity = Direction * Speed;
}

void AProjectile::SetSpeed(const float Speed)
{
	MovementComponent->InitialSpeed = Speed;
	MovementComponent->Velocity = MovementComponent->Velocity.GetSafeNormal() * Speed;
}


