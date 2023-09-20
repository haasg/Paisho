#include "Wave.h"

#include "Paisho/Character/PaishoVillain.h"
#include "Paisho/Util/DebugUtil.h"

UWave::UWave()
{
	
}

void UWave::Poll(const float GameTime)
{
	if(WaveData.IsActivelySpawning(GameTime))
	{
		switch(WaveData.GetSpawnType())
		{
		case EVillainSpawnType::PerSecond:
			if(GameTime > LastSpawnTime + WaveData.SecondsPerSpawn())
			{
				if(const TObjectPtr<UWorld> World = GetWorld())
				{
					PRINT("DOING SPAWN");
					const FVector SpawnLocation = FVector(1300, 1300, 100);
					const FTransform SpawnTransform = FTransform(SpawnLocation);
					APaishoVillain* Villain = World->SpawnActor<APaishoVillain>(WaveData.GetVillainClass(), SpawnTransform);
					Villains.Add(Villain);
				}
				LastSpawnTime = GameTime;
			}
			break;
		case EVillainSpawnType::AmountLimited:
			break;
		default:
			checkNoEntry();
		}
	}
}
