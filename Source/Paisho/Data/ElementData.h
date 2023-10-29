#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ElementType.h"
#include "ElementData.generated.h"

class UTexture2D;

UCLASS()
class PAISHO_API UElementData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FText Name;

	UPROPERTY(EditDefaultsOnly)
	EElement Element;

	UPROPERTY(EditDefaultsOnly)
	EElement ElementWeakness;

	UPROPERTY(EditDefaultsOnly)
	EElement ElementStrength;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UTexture2D> Icon;
};
