#include "PickupData.h"

#include "Paisho/GameWorld/Pickup.h"

UPickupData::UPickupData()
	: Type()
	, Value(0)
{
}

TSubclassOf<APickup> UPickupData::GetPickupClass() const
{
	check(PickupClass);
	return PickupClass;
}

EPickupType UPickupData::GetType() const
{
	return Type;
}

float UPickupData::GetValue() const
{
	return Value;
}

