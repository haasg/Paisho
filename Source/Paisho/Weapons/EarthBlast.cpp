#include "EarthBlast.h"

#include "Projectile.h"
#include "Paisho/Character/PaishoHero.h"
#include "Paisho/Data/WeaponData.h"
#include "Paisho/Util/DebugUtil.h"

void AEarthBlast::Fire()
{
	const TObjectPtr<AActor> ShooterActor = GetOwner();

	// this could be interface someday if we want to support other actors
	// if(TObjectPtr<APaishoHero> PaishoHero = Cast<APaishoHero>(ShooterActor))
	// {
	// 	const FVector SpriteDirection = PaishoHero->GetSpriteDirection();
	// 	
	// }
	const FRotator ShooterRotation = ShooterActor->GetActorRotation();
	const FVector ShooterFacingDirection = ShooterRotation.Vector();

	WARNING("Facing Direction is %s", *ShooterFacingDirection.ToString());
	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(AProjectile::StaticClass());
	Projectile->SetLocation(GetActorLocation());
	Projectile->SetSprite(WeaponData->GetProjectileSprite());
	Projectile->SetSpeed(WeaponData->GetProjectileSpeed());
	Projectile->SetDirection(FVector(1.f, 0.f, 0.f));
}
