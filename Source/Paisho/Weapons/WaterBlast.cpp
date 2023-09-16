#include "WaterBlast.h"

#include "Projectile.h"
#include "Paisho/Data/WeaponData.h"

void AWaterBlast::Fire()
{
	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(AProjectile::StaticClass());
	Projectile->SetActorLocation(GetActorLocation());
	Projectile->SetSprite(WeaponData->ProjectileSprite);
	Projectile->SetSpeed(WeaponData->ProjectileSpeed);
	Projectile->SetDirection(FVector(1.f, 0.f, 0.f));
}
