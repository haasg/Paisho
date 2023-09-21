#include "PaishoHero.h"

#include "ArsenalComponent.h"
#include "HealthBarComponent.h"
#include "HealthComponent.h"
#include "PaperFlipbook.h"
#include "StartingKit.h"
#include "XpComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Paisho/Data/HeroData.h"
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

	PickerUpperCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("PickerUpperCapsule"));
	PickerUpperCapsule->SetCollisionProfileName(FName("HeroPickerUpper"));
	PickerUpperCapsule->SetCapsuleHalfHeight(1000.0);
	PickerUpperCapsule->SetCapsuleRadius(200.0);
	PickerUpperCapsule->SetupAttachment(RootComponent);

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
	Health = CreateDefaultSubobject<UHealthComponent>(TEXT("Health"));
	HealthBar = CreateDefaultSubobject<UHealthBarComponent>(TEXT("HealthBar"));
	HealthBar->SetupAttachment(RootComponent);
	const FRotator HealthBarRotation = FRotator(90.f, 0.f, -90.f);
	HealthBar->SetRelativeRotation(HealthBarRotation);
	// const FVector HealthBarOffset = FVector(0, 200, 0);
	// HealthBar->SetRelativeLocation(HealthBarOffset);
	Arsenal = CreateDefaultSubobject<UArsenalComponent>(TEXT("Arsenal"));


	IdleAnimation = CreateDefaultSubobject<UPaperFlipbook>(TEXT("IdleAnimation"));
	WalkAnimation = CreateDefaultSubobject<UPaperFlipbook>(TEXT("WalkAnimation"));
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

	if(HeroData)
	{
		Health->Init(HeroData->StartingHealth, HeroData->StartingHealth);
		HealthBar->Init(Health);
		GetCharacterMovement()->MaxWalkSpeed = HeroData->MovementSpeed;
	}
	else
	{
		ERROR("Hero BeginPlay with nullptr HeroData");
	}

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

	
	if(Arsenal) // probably has authority here
	{
		Arsenal->Poll(DeltaSeconds);
	}
}
