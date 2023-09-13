#include "ArsenalComponent.h"

#include "Paisho/Weapons/Weapon.h"

void UArsenalComponent::Poll()
{
	for(auto& Weapon : Weapons)
	{
		Weapon->Fire();
	}
}
