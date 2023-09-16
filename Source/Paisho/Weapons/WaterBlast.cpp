#include "WaterBlast.h"

#include "Projectile.h"
#include "Paisho/Data/WeaponData.h"
#include "Paisho/Util/DebugUtil.h"

void AWaterBlast::Fire()
{
	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(AProjectile::StaticClass());
	Projectile->SetLocation(GetActorLocation());
	Projectile->SetSprite(WeaponData->GetProjectileSprite());
	Projectile->SetRotation(FRotator(0, 180, 0));
	Projectile->SetSpeed(WeaponData->GetProjectileSpeed());
	Projectile->SetDirection(FVector(1.f, 0.f, 0.f));
}
