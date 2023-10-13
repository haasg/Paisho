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

	// cache this
	if(APaishoGameState* GS = Cast<APaishoGameState>(GetWorld()->GetGameState()))
	{
		for(auto& PlayerState : GS->PlayerArray)
		{
			
		}
	}
}


void AStage::Tick(float DeltaSeconds)
{
	check(HasAuthority()); // this actor should only exist on the server
	
	Super::Tick(DeltaSeconds);

	float GameTime = 0;

	if(APaishoGameState* GS = Cast<APaishoGameState>(GetWorld()->GetGameState()))
	{
		GameTime = GS->GetGameTime();
		if(TOptional<FVector> MaybePlayerLocation = GS->ServerGetRandomPlayerLocation())
		{
			const FVector PlayerLocation = MaybePlayerLocation.GetValue();
			for(const auto& Wave : Waves)
            {
            	Wave->Poll(GameTime, PlayerLocation);
            }
		}
	} ELSE_ERROR("GameState is not of type APaishoGameState")
}

void AStage::Init(UStageData* NewStageData)
{
	StageData = NewStageData;
	for(auto& WaveData : StageData->Waves)
	{
		TObjectPtr<AWave> Wave = GetWorld()->SpawnActor<AWave>(AWave::StaticClass());
		Wave->Init(WaveData);
		Waves.Add(Wave);
	}
}
