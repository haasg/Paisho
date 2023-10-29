#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ElementType.h"
#include "ElementData.generated.h"

class UImage;

UCLASS()
class PAISHO_API UElementData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FText Name;

	UPROPERTY(EditDefaultsOnly)
	EElement ElementType;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UImage> Icon;
};
