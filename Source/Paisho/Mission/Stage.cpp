#include "Stage.h"

#include "StageData.h"
#include "Wave.h"

AStage::AStage()
{
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
