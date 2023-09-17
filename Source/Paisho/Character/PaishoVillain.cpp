#include "PaishoVillain.h"

#include "HealthBarComponent.h"
#include "HealthComponent.h"
#include "Components/CapsuleComponent.h"

APaishoVillain::APaishoVillain()
{
	GetCapsuleComponent()->SetCollisionProfileName(FName("Villain"));

	Health = CreateDefaultSubobject<UHealthComponent>(TEXT("Health"));
	HealthBar = CreateDefaultSubobject<UHealthBarComponent>(TEXT("HealthBar"));
	HealthBar->SetupAttachment(RootComponent);
	const FRotator HealthBarRotation = FRotator(90.f, 0.f, -90.f);
	HealthBar->SetRelativeRotation(HealthBarRotation);
}

void APaishoVillain::BeginPlay()
{
	Super::BeginPlay();

	Health->Init(100, 100);
	HealthBar->Init(Health);
}
