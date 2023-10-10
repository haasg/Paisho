#include "ArsenalComponent.h"

#include "Paisho/Data/WeaponData.h"
#include "Paisho/Util/DebugUtil.h"
#include "Paisho/Weapons/Weapon.h"

void UArsenalComponent::AddWeapon(UWeaponData* WeaponData)
{
	AActor* Owner = GetOwner();
	AWeapon* Weapon = GetWorld()->SpawnActor<AWeapon>(WeaponData->GetWeaponClass());
	Weapon->AttachToActor(Owner, FAttachmentTransformRules::KeepRelativeTransform);
	Weapon->SetWeaponData(WeaponData);
	Weapon->SetOwner(Owner);
	Weapons.Add(Weapon);
}

void UArsenalComponent::Poll(float DeltaSeconds)
{
	for(auto& Weapon : Weapons)
	{
		Weapon->Poll(DeltaSeconds);
	}
}
