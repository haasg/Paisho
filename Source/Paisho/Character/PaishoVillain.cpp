#include "PaishoVillain.h"

#include "HealthBarComponent.h"
#include "HealthComponent.h"
#include "PaperSpriteComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/GameStateBase.h"
#include "Paisho/Data/PickupData.h"
#include "Paisho/Data/VillainData.h"
#include "Paisho/Framework/PaishoGameState.h"
#include "Paisho/GameWorld/Pickup.h"
#include "Paisho/Util/DebugUtil.h"

APaishoVillain::APaishoVillain()
{
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	CapsuleComponent->SetCollisionProfileName(FName("Villain"));
	CapsuleComponent->SetSimulatePhysics(true);
	CapsuleComponent->SetCapsuleHalfHeight(500);
	CapsuleComponent->SetCapsuleRadius(50);
	CapsuleComponent->BodyInstance.LinearDamping = 1.0;
	CapsuleComponent->BodyInstance.AngularDamping = 1.0f;
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

void APaishoVillain::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AGameStateBase* GameState = GetWorld()->GetGameState();
	if(APaishoGameState* PaishoGameState = Cast<APaishoGameState>(GameState))
	{
		FVector PlayerLocation = PaishoGameState->GetPlayerLocation();
		FVector TargetDirection = (PlayerLocation - GetActorLocation()).GetSafeNormal2D();
		FVector DesiredVelocity = TargetDirection * 100.f;

		FVector CurrentVelocity = CapsuleComponent->GetPhysicsLinearVelocity();
		FVector ForceToAdd = (DesiredVelocity - CurrentVelocity) * 100.f;  // assuming Force = mass * acceleration
		CapsuleComponent->AddForce(ForceToAdd, NAME_None, true);
	}
}

void APaishoVillain::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//PRINT("Villain hit %s", *OtherActor->GetName());
}

void APaishoVillain::OnDeath()
{
	//PRINT("VILLAIN ON DEATH SPAWNING A PICKUP");
	if(PickupData)
	{
		if(const TObjectPtr<UWorld> World = GetWorld())
		{
			const FTransform VillainTransform = this->GetActorTransform();
			World->SpawnActor<APickup>(PickupData->GetPickupClass(), VillainTransform);
		}
	}
	Destroy();
}