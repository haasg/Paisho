#include "EarthBlast.h"

#include "Projectile.h"
#include "Paisho/Data/WeaponData.h"

void AEarthBlast::Fire()
{
	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(AProjectile::StaticClass());
	Projectile->SetLocation(GetActorLocation());
	Projectile->SetSprite(WeaponData->GetProjectileSprite());
	Projectile->SetSpeed(WeaponData->GetProjectileSpeed());
	Projectile->SetDirection(FVector(1.f, 0.f, 0.f));
}