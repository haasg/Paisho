#include "Weapon.h"

#include "PaperSpriteComponent.h"
#include "Projectile.h"
#include "Paisho/Data/WeaponData.h"

AWeapon::AWeapon()
{
	WeaponData = nullptr;
}

void AWeapon::Fire()
{
	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(AProjectile::StaticClass());
	Projectile->SetActorLocation(GetActorLocation());
	Projectile->SpriteComponent->SetSprite(WeaponData->ProjectileSprite);
	
}
