#include "PickupData.h"

#include "Paisho/GameWorld/Pickup.h"

UPickupData::UPickupData()
{
}

TSubclassOf<APickup> UPickupData::GetPickupClass() const
{
	check(PickupClass);
	return PickupClass;
}
