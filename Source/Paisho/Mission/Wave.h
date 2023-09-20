#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Paisho/Data/VillainData.h"

#include "Wave.generated.h"

class APaishoVillain;
class UVillainData;


UENUM(BlueprintType)
enum class EVillainSpawnType : uint8
{
	PerSecond,
	AmountLimited
};

USTRUCT()
struct FVillainSpawnType
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	EVillainSpawnType Type = EVillainSpawnType::PerSecond;

	UPROPERTY(EditDefaultsOnly, meta = (EditCondition = "Type == EVillainSpawnType::PerSecond"))
	float SpawnsPerSecond = 0;

	UPROPERTY(EditDefaultsOnly, meta = (EditCondition = "Type == EVillainSpawnType::AmountLimited"))
	float AmountToSpawn = 0;
};

USTRUCT(BlueprintType)
struct FWaveData
{
	GENERATED_BODY()
	
	float Start() const {return SpawnStart; }
	float End() const { return SpawnStart + SpawnDuration; }
	bool IsActivelySpawning(const float GameTime) const { return GameTime >= Start() && GameTime < End(); }
	EVillainSpawnType GetSpawnType() const { return SpawnType.Type; }
	float SecondsPerSpawn() { check(SpawnType.SpawnsPerSecond != 0.f); return 1.f / SpawnType.SpawnsPerSecond;}
	TSubclassOf<APaishoVillain> GetVillainClass() const { return VillainData->VillainClass; }

private:
	UPROPERTY(EditAnywhere)
	float SpawnStart = 0;

	UPROPERTY(EditAnywhere)
	float SpawnDuration = 0;

	UPROPERTY(EditAnywhere)
	FVillainSpawnType SpawnType;

	UPROPERTY(EditAnywhere)
	UVillainData* VillainData = nullptr; 
};

UCLASS()
class PAISHO_API UWave : public UObject
{
	GENERATED_BODY()
	
public:
	UWave();
	void Init(const FWaveData& NewWaveData) { WaveData = NewWaveData; }
	void Poll(const float GameTime, FVector PlayerLocation);

	FWaveData GetWaveData() const { return WaveData; }
	int32 GetVillainsAlive() const { return Villains.Num(); }

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FWaveData WaveData;

	// Wave Instance
	UPROPERTY()
	TArray<TObjectPtr<APaishoVillain>> Villains;

	UPROPERTY()
	float LastSpawnTime;
	
};
