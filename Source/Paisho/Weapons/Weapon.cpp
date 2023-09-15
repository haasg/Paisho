#include "Weapon.h"

#include "PaperSpriteComponent.h"
#include "Projectile.h"
#include "Paisho/Data/WeaponData.h"

AWeapon::AWeapon()
{
	WeaponData = nullptr;
}

void AWeapon::Poll(float DeltaSeconds)
{
	if(SecondsSinceLastFire > 1.f)
	{
		SecondsSinceLastFire = 0.f;
		this->Fire();
	}
	SecondsSinceLastFire += DeltaSeconds;
}

void AWeapon::Fire()
{
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(AProjectile::StaticClass());
		//Projectile->InitFromData(WeaponData);
		Projectile->SetActorLocation(GetActorLocation());
		Projectile->SetSprite(WeaponData->ProjectileSprite);
		Projectile->SetSpeed(WeaponData->ProjectileSpeed);
		Projectile->SetDirection(FVector(1.f, 0.f, 0.f));
		//Projectile->SpriteComponent->SetSprite(WeaponData->ProjectileSprite);
}
