﻿#include "Pickup.h"

#include "PaperSpriteComponent.h"
#include "Components/CapsuleComponent.h"

APickup::APickup()
{
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	//CapsuleComponent->SetCollsionProfile TO PICKUP
	SetRootComponent(CapsuleComponent);

	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	SpriteComponent->SetupAttachment(RootComponent);
}

void APickup::BeginPlay()
{
	Super::BeginPlay();
}