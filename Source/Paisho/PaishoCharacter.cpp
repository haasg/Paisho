#include "PaishoCharacter.h"

#include "Camera/CameraComponent.h"
#include "Framework/PaishoPlayerState.h"
#include "GameFramework/SpringArmComponent.h"

APaishoCharacter::APaishoCharacter()
{
	bReplicates = true;
	//SetReplicatedMovement(true);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bDoCollisionTest = false;
	SpringArm->bUsePawnControlRotation = false;
	// const FRotator SpringArmRotation = FRotator(-90.f, 0.f, 270.f);
	// SpringArm->SetWorldRotation(SpringArmRotation);
	SpringArm->TargetArmLength = 1920.0f;
	

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;
}

void APaishoCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	APaishoPlayerState* PS = Cast<APaishoPlayerState>(GetPlayerState());
	if (PS && HasAuthority())
	{
		PS->SetPlayerLocation(GetActorLocation()); 
	}

	UE_LOG(LogTemp, Warning, TEXT("Player Location: %s"), *GetActorLocation().ToString());
}
