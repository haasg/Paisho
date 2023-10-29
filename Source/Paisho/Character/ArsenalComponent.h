#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Paisho/Data/LevelUpTypes.h"

#include "ArsenalComponent.generated.h"

class UWeaponData;
class AWeapon;

UCLASS()
class UArsenalComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UArsenalComponent() {}

	void AddWeapon(UWeaponData* WeaponData);
	void Poll(float DeltaSeconds);

	TArray<FWeaponLevelUpInfo> CalcWeaponLevelUpInfos(int32 Amount) const;

private:
	UPROPERTY(VisibleAnywhere)
	TArray<TObjectPtr<AWeapon>> Weapons;

	TObjectPtr<AWeapon> GetRandomWeapon() const;
};
