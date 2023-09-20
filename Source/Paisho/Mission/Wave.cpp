#include "Wave.h"

#include "Paisho/Character/PaishoVillain.h"
#include "Paisho/Util/DebugUtil.h"

UWave::UWave()
{
	
}

void UWave::Poll(const float GameTime, FVector PlayerLocation)
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
					float RandomAngle = FMath::RandRange(0.f, 2.f * PI);
					float RandomRadius = FMath::RandRange(500, 800);

					// Step 3: Calculate the X and Y offsets
					float XOffset = RandomRadius * FMath::Cos(RandomAngle);
					float YOffset = RandomRadius * FMath::Sin(RandomAngle);

					// Step 4: Get the new spawn point
					FVector SpawnPoint = FVector(PlayerLocation.X + XOffset, PlayerLocation.Y + YOffset, PlayerLocation.Z);
					const FTransform SpawnTransform = FTransform(SpawnPoint);
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
