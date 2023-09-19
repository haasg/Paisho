#include "PaishoGameState.h"

void APaishoGameState::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	GameTime += DeltaSeconds;
}
