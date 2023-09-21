#include "PaishoVillain.h"

#include "HealthBarComponent.h"
#include "HealthComponent.h"
#include "PaperSpriteComponent.h"
#include "Components/CapsuleComponent.h"
#include "Paisho/Data/VillainData.h"
#include "Paisho/Util/DebugUtil.h"

APaishoVillain::APaishoVillain()
{
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	CapsuleComponent->SetCollisionProfileName(FName("Villain"));
	CapsuleComponent->SetSimulatePhysics(true);
	// CapsuleComponent->SetCapsuleHalfHeight(100);
	// CapsuleComponent->SetCapsuleRadius(50);
	SetRootComponent(CapsuleComponent);

	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	SpriteComponent->SetupAttachment(RootComponent);

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
		//GetCharacterMovement()->MaxWalkSpeed = VillainData->MovementSpeed;
	}
	else
	{
		ERROR("Villain BeginPlay with nullptr VillainData");
	}

	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::HandleOverlap);
	Health->OnDeath.AddDynamic(this, &ThisClass::OnDeath);
	
}

void APaishoVillain::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PRINT("Villain hit %s", *OtherActor->GetName());
}

void APaishoVillain::OnDeath()
{
	Destroy();
}