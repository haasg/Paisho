﻿#include "PaishoVillain.h"

#include "HealthBarComponent.h"
#include "HealthComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Paisho/Data/VillainData.h"
#include "Paisho/Util/DebugUtil.h"

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
	Tags.Add(FName("Villain"));

	if(VillainData)
	{
		Health->Init(VillainData->StartingHealth, VillainData->StartingHealth);
		HealthBar->Init(Health);
		GetCharacterMovement()->MaxWalkSpeed = VillainData->MovementSpeed;
	}
	else
	{
		ERROR("Villain BeginPlay with nullptr VillainData");
	}

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::HandleOverlap);
	
}

void APaishoVillain::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PRINT("Villain hit %s", *OtherActor->GetName());
}