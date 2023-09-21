#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "XpComponent.generated.h"

UCLASS()
class UXpComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UXpComponent();

	// float TotalXp() const;
	// float XpToNextLevel() const;
	// float XpFromPreviousLevel() const;
	// int Level() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Xp = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCurveTable> LevelCurveTable;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UCurveTable> LevelCurveTableClass;
	
};
