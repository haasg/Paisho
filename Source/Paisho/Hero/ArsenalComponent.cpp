#include "ArsenalComponent.h"

#include "Paisho/Weapons/Weapon.h"

void UArsenalComponent::Poll(float DeltaSeconds)
{
	for(auto& Weapon : Weapons)
	{
		Weapon->Poll(DeltaSeconds);
	}
}
