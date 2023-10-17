#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "WaterBasic.generated.h"

UCLASS()
class PAISHO_API AWaterBasic : public AWeapon
{
	GENERATED_BODY()

	virtual void Fire() override;
};
