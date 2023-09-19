#include "PaishoGameState.h"

void APaishoGameState::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	/* REPLICATE THIS FROM GAMEMODE EVENTUALLY */
	GameTime += DeltaSeconds;
}
