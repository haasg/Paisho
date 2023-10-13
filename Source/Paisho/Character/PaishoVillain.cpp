#include "PaishoVillain.h"

#include "HealthBarComponent.h"
#include "HealthComponent.h"
#include "PaperSpriteComponent.h"
#include "Components/CapsuleComponent.h"
#include "Paisho/Framework/PaishoGameState.h"
#include "Paisho/Data/PickupData.h"
#include "Paisho/Data/VillainData.h"
#include "Paisho/Framework/PaishoGameState.h"
#include "Paisho/GameWorld/Pickup.h"
#include "Paisho/Util/DebugUtil.h"

APaishoVillain::APaishoVillain()
{
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	CapsuleComponent->SetCollisionProfileName(FName("Villain"));
	CapsuleComponent->SetCapsuleHalfHeight(500);
	CapsuleComponent->SetCapsuleRadius(50);
	CapsuleComponent->BodyInstance.LinearDamping = 1.0;
	CapsuleComponent->BodyInstance.AngularDamping = 1.0f;
	SetRootComponent(CapsuleComponent);

	if(HasAuthority())
	{ 
		CapsuleComponent->SetSimulatePhysics(true);
	}

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
	} ELSE_ERROR("Villain BeginPlay with nullptr VillainData");

	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::HandleOverlap);
	Health->OnDeath.AddDynamic(this, &ThisClass::OnDeath);

	if(const TObjectPtr<APaishoGameState> GameState = GetWorld()->GetGameState<APaishoGameState>())
	{
		GameState->RegisterVillain(this);
	} ELSE_ERROR("Villain BeginPlay with nullptr GameState")
	
}

void APaishoVillain::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// TODO: Cache the gamestate as paishogamestate
	// TODO: Only run on the server
	// TODO: Make sure villain location is replicated
	if(HasAuthority())
	{
		AGameStateBase* GameState = GetWorld()->GetGameState();
		if(APaishoGameState* PaishoGameState = Cast<APaishoGameState>(GameState))
		{
			const FVector PlayerLocation = PaishoGameState->GetPlayerLocation();
			const FVector TargetDirection = (PlayerLocation - GetActorLocation()).GetSafeNormal2D();
			const FVector DesiredVelocity = TargetDirection * 100.f;
			
			CapsuleComponent->AddForce(DesiredVelocity, NAME_None, true);
		}
	}
}

/* It's possible the server will fully destroy the actor before a client is able to run this OnDeath() function */
/* Put any logic that needs to run on all clients in EndPlay() */
void APaishoVillain::OnDeath()
{
	Destroy(); // Will call APaishoVillain::EndPlay
}

void APaishoVillain::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if(PickupData)
	{
		if(const TObjectPtr<UWorld> World = GetWorld())
		{
			const FTransform VillainTransform = this->GetActorTransform();
			World->SpawnActor<APickup>(PickupData->GetPickupClass(), VillainTransform);
		}
	}
	if(const TObjectPtr<APaishoGameState> GameState = GetWorld()->GetGameState<APaishoGameState>())
	{
		GameState->UnregisterVillain(this);
	} ELSE_ERROR("Villain death with nullptr GameState")
}

void APaishoVillain::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//PRINT("Villain hit %s", *OtherActor->GetName());
}

