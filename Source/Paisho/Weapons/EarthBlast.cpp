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
		const float FacingDirection = PaishoHero->GetSpriteLeftRightDirection();
		const FVector ShootingDirection = FVector(FacingDirection, 0, 0);
		
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(AProjectile::StaticClass());
		Projectile->SetWeaponData(WeaponData);
		Projectile->SetLevel(Level);
		Projectile->SetLocation(GetActorLocation());
		
		Projectile->SetSpeed(WeaponData->GetSpeed(Level));
		Projectile->SetDirection(ShootingDirection);
		if(FacingDirection < 0)
		{
			Projectile->SetRotation(FRotator(180, 0, 0));	
		}
		
	}
}




