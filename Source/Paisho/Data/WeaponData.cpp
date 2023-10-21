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

float UWeaponData::GetSpeed(const int Level) const
{
	return ProjectileSpeed.GetValueAtLevel(Level);
}

float UWeaponData::GetLifetime(const int Level) const
{
	return ProjectileLifetime.GetValueAtLevel(Level);
}

float UWeaponData::GetScale(const int Level) const
{
	return ProjectileScale.GetValueAtLevel(Level);
}

float UWeaponData::GetMaxHits(const int Level) const
{
	return ProjectileMaxHits.GetValueAtLevel(Level);
}

float UWeaponData::GetDamage(const int Level) const
{
	return ProjectileDamage.GetValueAtLevel(Level);
}



TObjectPtr<UPaperSprite> UWeaponData::GetProjectileSprite() const
{
	return ProjectileSprite;
}
