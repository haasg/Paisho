#include "PaishoPlayerState.h"

#include "Net/UnrealNetwork.h"

void APaishoPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(APaishoPlayerState, PlayerLocation);
}
