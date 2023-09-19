#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Wave.generated.h"

class APaishoVillain;
class UVillainData;

USTRUCT(BlueprintType)
struct FWaveData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Start;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Duration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Size;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UVillainData* VillainData; 
};

UCLASS()
class PAISHO_API UWave : public UObject
{
	GENERATED_BODY()
	
public:
	UWave();
	void Init(const FWaveData& NewWaveData) { WaveData = NewWaveData; } 

	FWaveData GetWaveData() const { return WaveData; }
	int32 GetVillainsAlive() const { return Villains.Num(); }

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FWaveData WaveData;

	// Wave Instance
	UPROPERTY()
	TArray<TObjectPtr<APaishoVillain>> Villains;
	
};
