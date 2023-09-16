#include "PaishoHero.h"

#include "ArsenalComponent.h"
#include "PaperFlipbook.h"
#include "StartingKit.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Paisho/Framework/PaishoPlayerState.h"
#include "Paisho/Weapons/Weapon.h"

APaishoHero::APaishoHero()
{
	bReplicates = true;
	//SetReplicatedMovement(true);

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

	if(StartingKit)
	{
		for(auto& WeaponData : StartingKit->Weapons)
		{
			Arsenal->AddWeapon(WeaponData);
		}
	}

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

	// // fire the test weapon
	// if (Weapon)
	// {
	// 	Weapon->Poll(DeltaSeconds);
	// }

	
	if(Arsenal) // probably has authority here
	{
		Arsenal->Poll(DeltaSeconds);
	}
}