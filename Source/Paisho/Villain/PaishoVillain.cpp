#include "PaishoVillain.h"

#include "Components/CapsuleComponent.h"

APaishoVillain::APaishoVillain()
{
	GetCapsuleComponent()->SetCollisionProfileName(FName("Villain"));
}
