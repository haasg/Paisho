#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "XpComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnXpChangedEvent);

/* Probably some premature optimization here, but seems pretty encapsulated */
USTRUCT()
struct FXpInfoCache
{
	GENERATED_BODY()

	int CurrentLevel;
	float XpToLevelUp;
	float XpSinceLevelUp;
	float XpRequiredForNextLevel;
	float XpRequiredToBeCurrentLevel;
	float PercentThroughLevel;
};

UCLASS()
class UXpComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UXpComponent();

	void AddXp(int32 Amount);

	float CurrentXp() const;
	int CurrentLevel();
	int NextLevel();
	float XpSinceLevelUp();
	float XpRequiredForNextLevel();
	float XpRequiredToBeCurrentLevel();
	float PercentThroughLevel();
	
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnXpChangedEvent OnXpChanged;

protected:
	void CleanCacheIfDirty();
	bool bIsDirty = true;
	FXpInfoCache XpInfoCache;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Xp = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCurveTable> LevelCurveTable;
};


