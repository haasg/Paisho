#include "Weapon.h"

#include "PaperSpriteComponent.h"
#include "Projectile.h"
#include "Paisho/Data/WeaponData.h"
#include "Paisho/Util/DebugUtil.h"

AWeapon::AWeapon()
{
	WeaponData = nullptr;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}

void AWeapon::Poll(float DeltaSeconds)
{
	const float SecondsBetweenShots = WeaponData->PrimarySecondsPerShot();
	if(SecondsSinceLastFire > SecondsBetweenShots)
	{
		SecondsSinceLastFire = 0.f;
		this->Fire();
	}
	SecondsSinceLastFire += DeltaSeconds;
}

