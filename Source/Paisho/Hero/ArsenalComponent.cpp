#include "ArsenalComponent.h"

#include "Paisho/Weapons/Weapon.h"

void UArsenalComponent::AddWeapon(UWeaponData* WeaponData)
{
	AActor* Owner = GetOwner();
	AWeapon* Weapon = GetWorld()->SpawnActor<AWeapon>(AWeapon::StaticClass());
	Weapon->AttachToActor(Owner, FAttachmentTransformRules::KeepRelativeTransform);
	Weapon->SetWeaponData(WeaponData);
	Weapons.Add(Weapon);
}

void UArsenalComponent::Poll(float DeltaSeconds)
{
	for(auto& Weapon : Weapons)
	{
		Weapon->Poll(DeltaSeconds);
	}
}
