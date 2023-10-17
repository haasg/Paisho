#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "FireBasic.generated.h"

UCLASS()
class PAISHO_API AFireBasic : public AWeapon
{
	GENERATED_BODY()

public:
	AFireBasic();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
