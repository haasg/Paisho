#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "WaterBasic.generated.h"

UCLASS()
class PAISHO_API AWaterBasic : public AActor
{
	GENERATED_BODY()

public:
	AWaterBasic();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
