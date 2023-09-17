#include "PaishoVillain.h"

#include "HealthBarComponent.h"
#include "HealthComponent.h"
#include "Components/CapsuleComponent.h"

APaishoVillain::APaishoVillain()
{
	GetCapsuleComponent()->SetCollisionProfileName(FName("Villain"));
}

void APaishoVillain::BeginPlay()
{
	Super::BeginPlay();

	Health->Init(100, 100);
	HealthBar->Init(Health);
}
