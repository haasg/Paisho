#include "PaishoHero.h"

#include "ArsenalComponent.h"
#include "HealthBarComponent.h"
#include "HealthComponent.h"
#include "PaperFlipbook.h"
#include "PaperFlipbookComponent.h"
#include "PickerUpperComponent.h"
#include "StartingKit.h"
#include "XpComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Net/UnrealNetwork.h"
#include "Paisho/Data/HeroData.h"
#include "Paisho/Data/PickupData.h"
#include "Paisho/Framework/PaishoPlayerController.h"
#include "Paisho/Framework/PaishoPlayerState.h"
#include "Paisho/Util/DebugUtil.h"
#include "Paisho/Weapons/Weapon.h"

APaishoHero::APaishoHero()
{
	bReplicates = true;
	//SetReplicatedMovement(true);

	GetCapsuleComponent()->SetCollisionProfileName(FName("HeroCoreBlock"));
	GetCapsuleComponent()->SetCapsuleHalfHeight(1000.0);
	GetCapsuleComponent()->SetCapsuleRadius(40.0);
	SetRootComponent(GetCapsuleComponent());

	HitboxCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("HitboxCapsule"));
	HitboxCapsule->SetCollisionProfileName(FName("HeroHitbox"));
	HitboxCapsule->SetCapsuleHalfHeight(1000.0);
	HitboxCapsule->SetCapsuleRadius(50.0);
	HitboxCapsule->SetupAttachment(RootComponent);

	PickerUpperComponent = CreateDefaultSubobject<UPickerUpperComponent>(TEXT("PickerUpperComponent"));
	PickerUpperComponent->SetupAttachment(RootComponent);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bDoCollisionTest = false;
	SpringArm->bUsePawnControlRotation = false;
	const FRotator SpringArmRotation = FRotator(-90.f, 0.f, -90.f);
	SpringArm->SetWorldRotation(SpringArmRotation);
	SpringArm->TargetArmLength = 1920.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	XpComponent = CreateDefaultSubobject<UXpComponent>(TEXT("XpComponent"));
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health"));
	HealthBarComponent = CreateDefaultSubobject<UHealthBarComponent>(TEXT("HealthBar"));
	HealthBarComponent->SetupAttachment(RootComponent);
	const FRotator HealthBarRotation = FRotator(90.f, 0.f, -90.f);
	HealthBarComponent->SetRelativeRotation(HealthBarRotation);
	// const FVector HealthBarOffset = FVector(0, 200, 0);
	// HealthBar->SetRelativeLocation(HealthBarOffset);
	Arsenal = CreateDefaultSubobject<UArsenalComponent>(TEXT("Arsenal"));


	IdleAnimation = CreateDefaultSubobject<UPaperFlipbook>(TEXT("IdleAnimation"));
	WalkAnimation = CreateDefaultSubobject<UPaperFlipbook>(TEXT("WalkAnimation"));
	FacingDirection2d = CreateDefaultSubobject<UArrowComponent>(TEXT("FacingDirection2d"));
	FacingDirection2d->SetupAttachment(RootComponent);
	SpriteDirectionLeftRight = CreateDefaultSubobject<UArrowComponent>(TEXT("SpriteDirectionLeftRight"));
	SpriteDirectionLeftRight->SetupAttachment(RootComponent);
}

APaishoHero* APaishoHero::FromData(UHeroData* HeroData, UWorld* World)
{
	return nullptr;//not sure what to do with this yet, want some better way to create a hero from data
	// maybe i do just end up making a dumb init function to follow the spawn actor call from elsewhere :/
}

void APaishoHero::BeginPlay()
{
    Super::BeginPlay();
	Tags.Add(FName("Hero"));

	if(const TObjectPtr<APaishoPlayerController> PC = Cast<APaishoPlayerController>(Controller))
	{
		PaishoController = PC;
		PaishoController->BindHealthComponentToHud(HealthComponent);
		PaishoController->BindXpComponentToHud(XpComponent);
	}

	if(HeroData)
	{
		HealthComponent->Init(HeroData->StartingHealth, HeroData->StartingHealth);
		HealthBarComponent->Init(HealthComponent);
		GetCharacterMovement()->MaxWalkSpeed = HeroData->MovementSpeed;
	} ELSE_ERROR("Hero BeginPlay with nullptr HeroData")

	XpComponent->OnLevelUp.AddDynamic(this, &APaishoHero::HandleLevelUp);
	if(StartingKit)
	{
		for(auto& WeaponData : StartingKit->Weapons)
		{
			Arsenal->AddWeapon(WeaponData);
		}
	}

	
	//HealthBar->SetHiddenInGame(false);

    // Weapon = GetWorld()->SpawnActor<AWeapon>(WeaponClass);
    // Weapon->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

void APaishoHero::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	APaishoPlayerState* PS = Cast<APaishoPlayerState>(GetPlayerState());
	if (PS && HasAuthority())
	{
		PS->SetPlayerLocation(GetActorLocation()); 
	}
	
	//PRINT("LOCATION: %s", *GetActorLocation().ToString());
	
	if(Arsenal && HasAuthority()) 
	{
		Arsenal->Poll(DeltaSeconds);
	}
}

void APaishoHero::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APaishoHero, MovementIntent);
}

void APaishoHero::OnPickup(UPickupData* PickupData)
{
	switch(PickupData->GetType())
	{
		// case EPickupType::Weapon:
		// {
		// 	if(const TObjectPtr<UWorld> World = GetWorld())
		// 	{
		// 		if(const TObjectPtr<AWeapon> Weapon = World->SpawnActor<AWeapon>(PickupData->GetWeaponClass()))
		// 		{
		// 			Arsenal->AddWeapon(Weapon);
		// 		}
		// 	}
		// 	break;
		// }
		case EPickupType::Health:
		{
			HealthComponent->Heal(1);
			break;
		}
		case EPickupType::Xp:
		{
			XpComponent->AddXp(1);
			break;
		}
		default:
		{
			ERROR("Unhandled PickupType");
			break;
		}
	}
}

void APaishoHero::HandleLevelUp(int NewLevel)
{
	PRINT("WE LEVELED UP!");
}


void APaishoHero::LocalSetMovementIntent(const FVector& NewMovementIntent)
{
	/* Tell server we want to move in a new direction */
	ServerSetMovementIntent(NewMovementIntent);
	/* Immediately update visual elements locally for responsiveness */ 
	UpdateMovementIntent(NewMovementIntent);
}

void APaishoHero::ServerSetMovementIntent_Implementation(const FVector& NewMovementIntent)
{
	/* MovementIntent will be replicated to simulated proxies */
	UpdateMovementIntent(NewMovementIntent);
}

void APaishoHero::OnRep_MovementIntent()
{
	UpdateMovementIntent(this->MovementIntent);
}

void APaishoHero::UpdateMovementIntent(const FVector& NewMovementIntent)
{
	MovementIntent = NewMovementIntent;

	const FVector CurrentFacingDirection = GetFacingDirection();
	if(NewMovementIntent != CurrentFacingDirection)
	{
		FacingDirection2d->SetWorldRotation(MovementIntent.Rotation());	
	}

	const float CurrentLeftRight = GetSpriteLeftRightDirection();
	if(NewMovementIntent.X != CurrentLeftRight && NewMovementIntent.X != 0)
	{
		const FVector Direction = FVector(MovementIntent.X, 0, 0);
		SpriteDirectionLeftRight->SetWorldRotation(Direction.Rotation());
	}
}

FVector APaishoHero::GetFacingDirection()
{
	return FacingDirection2d->GetForwardVector();
}

FVector2d APaishoHero::GetFacingDirection2d()
{
	const FVector MovementDirection = GetFacingDirection();
	return FVector2d(MovementDirection.X, MovementDirection.Y);
}

float APaishoHero::GetSpriteLeftRightDirection()
{
	return SpriteDirectionLeftRight->GetForwardVector().X;
}
