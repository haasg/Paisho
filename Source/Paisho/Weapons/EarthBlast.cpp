#include "EarthBlast.h"

#include "Projectile.h"
#include "Paisho/Character/PaishoHero.h"
#include "Paisho/Data/WeaponData.h"
#include "Paisho/Util/DebugUtil.h"

void AEarthBlast::Fire()
{
	const TObjectPtr<AActor> WeaponHolder = GetOwner();

	//this could be interface someday if we want to support other actors
	if(const TObjectPtr<APaishoHero> PaishoHero = Cast<APaishoHero>(WeaponHolder))
	{
		const FVector2d FacingDirection = PaishoHero->GetFacingDirection2d();
		const FVector ShootingDirection = FVector(FacingDirection.X, 0, 0);
		
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(AProjectile::StaticClass());
		Projectile->SetLocation(GetActorLocation());
		Projectile->SetSprite(WeaponData->GetProjectileSprite());
		Projectile->SetSpeed(WeaponData->GetProjectileSpeed());
		Projectile->SetDirection(ShootingDirection);
		Projectile->SetRotation(ShootingDirection.Rotation());
	}
}




