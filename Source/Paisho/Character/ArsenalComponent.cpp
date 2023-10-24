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

TArray<FWeaponLevelUpInfo> UArsenalComponent::CalcWeaponLevelUpInfos(const int32 Amount) const
{
	if(Weapons.Num() == 0) { return TArray<FWeaponLevelUpInfo>(); }
	
	TArray<FWeaponLevelUpInfo> Infos;
	for(int i = 0; i < Amount; i++)
	{
		FWeaponLevelUpInfo Info;
		const TObjectPtr<AWeapon> RandomWeapon = GetRandomWeapon();
		Info.WeaponData = RandomWeapon->GetWeaponData();
		Info.CurrentLevel = RandomWeapon->GetWeaponLevel();
		Infos.Add(Info);
	}
	return Infos;
}

TObjectPtr<AWeapon> UArsenalComponent::GetRandomWeapon() const
{
	if(Weapons.Num() == 0) { return nullptr; }
	return Weapons[FMath::RandRange(0, Weapons.Num() - 1)];
}
