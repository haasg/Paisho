#include "PaishoGameModeBase.h"

#include "Paisho/Mission/Stage.h"

void APaishoGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentStage = GetWorld()->SpawnActor<AStage>(AStage::StaticClass());
	CurrentStage->Init(StageData);
}
