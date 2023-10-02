#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "PickupInterface.generated.h"

UINTERFACE()
class UPickupInterface : public UInterface
{
	GENERATED_BODY()
};

class IPickupInterface
{
	GENERATED_BODY()

public:
	virtual void OnPickup() = 0;
	
};

