#include "PaishoCharacter.h"

#include "Framework/PaishoPlayerState.h"

void APaishoCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	APaishoPlayerState* PS = Cast<APaishoPlayerState>(GetPlayerState());
	if (PS && HasAuthority())
	{
		PS->SetPlayerLocation(GetActorLocation()); 
	}
}
