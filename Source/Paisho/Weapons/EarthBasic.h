﻿#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "EarthBasic.generated.h"

UCLASS()
class PAISHO_API AEarthBasic : public AWeapon
{
	GENERATED_BODY()

	virtual void Fire() override;
};
