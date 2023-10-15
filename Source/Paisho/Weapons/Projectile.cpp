#include "Projectile.h"

#include "PaperSpriteComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Net/UnrealNetwork.h"
#include "Paisho/Character/HealthComponent.h"
#include "Paisho/Data/WeaponData.h"
#include "Paisho/Util/DebugUtil.h"

AProjectile::AProjectile()
{
	bReplicates = true;
	AActor::SetReplicateMovement(true);
	bAlwaysRelevant = true;
	
	CollisionCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionCapsule"));
	CollisionCapsule->SetCollisionProfileName(FName("Projectile"));
	RootComponent = CollisionCapsule;
	
	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	const FRotator Rotator = FRotator(0.f, 0.f, -90.f);
	SpriteComponent->SetWorldRotation(Rotator);
	SpriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision); // Collision is handled by capsule
	SpriteComponent->SetupAttachment(RootComponent);

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));
	MovementComponent->InitialSpeed = 1000.f;
	MovementComponent->Velocity = FVector(500.f, 0.f, 0.f);
	MovementComponent->MaxSpeed = 1000.f;
	MovementComponent->ProjectileGravityScale = 0.f;
	MovementComponent->bShouldBounce = false;
	MovementComponent->SetIsReplicated(true);
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	

	CollisionCapsule->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::HandleOverlap);
}

void AProjectile::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AProjectile, WeaponData);
}


void AProjectile::SetSprite(UPaperSprite* Sprite)
{
	SpriteComponent->SetSprite(Sprite);
}

void AProjectile::SetRotation(const FRotator& Rotation)
{
	SpriteComponent->AddRelativeRotation(Rotation);
}

void AProjectile::SetLocation(const FVector& Location)
{
	CollisionCapsule->SetWorldLocation(Location);
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

void AProjectile::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(UHealthComponent* Health = OtherActor->FindComponentByClass<UHealthComponent>())
	{
		Health->TakeDamage(1.f);
	}
	//PRINT("Projectile hit %s", *OtherActor->GetName());
}

void AProjectile::OnRep_WeaponData()
{
	PRINT("ON REP WEAPON DATA");
	if(WeaponData)
	{
		SetSprite(WeaponData->GetProjectileSprite());
	}
	
}


