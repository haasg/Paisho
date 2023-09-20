#include "Stage.h"

#include "StageData.h"
#include "Wave.h"
#include "Paisho/Framework/PaishoGameState.h"
#include "Paisho/Util/DebugUtil.h"

AStage::AStage()
{
	PrimaryActorTick.bCanEverTick = true;
	StageData = nullptr;
}

void AStage::BeginPlay()
{
	Super::BeginPlay();

	for(auto& WaveData : StageData->Waves)
	{
		const TObjectPtr<UWave> Wave = NewObject<UWave>(this, UWave::StaticClass());
		Wave->Init(WaveData);
		Waves.Add(Wave);
	}
}

void AStage::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	float GameTime = 0;
	if(APaishoGameState* GS = Cast<APaishoGameState>(GetWorld()->GetGameState()))
	{
		GameTime = GS->GetGameTime();	
	} else
	{
		ERROR("GameState is not of type APaishoGameState");
	}
	for(const auto& Wave : Waves)
	{
		Wave->Poll(GameTime);
	}
	
}
