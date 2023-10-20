#include "WeaponData.h"

TSubclassOf<AWeapon> UWeaponData::GetWeaponClass() const
{
	return WeaponClass;
}

float UWeaponData::PrimaryRpm() const
{
	check(FireType.PrimaryRpm > 0.0);
	return FireType.PrimaryRpm;
}

float UWeaponData::PrimarySecondsPerShot() const
{
	check(FireType.PrimaryRpm > 0.0);
	return 60.f / FireType.PrimaryRpm;
}

float UWeaponData::GetProjectileSpeed() const
{
	return ProjectileSpeed;
}

float UWeaponData::GetDamage() const
{
	return ProjectileDamage;
}

TObjectPtr<UPaperSprite> UWeaponData::GetProjectileSprite() const
{
	return ProjectileSprite;
}
