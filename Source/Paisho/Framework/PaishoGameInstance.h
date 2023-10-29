#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PaishoGameInstance.generated.h"

class UElementData;

UCLASS()
class PAISHO_API UPaishoGameInstance : public UGameInstance
{
	GENERATED_BODY()

	/* Framework */
public:
	virtual void Init() override;

	
	
	/* Element Data */
public:
	FORCEINLINE TArray<TObjectPtr<UElementData>> GetElementDataAtlas() const { return ElementDataAtlas; }
protected:
	void LoadDataAssets();
	void ElementAssetsLoadComplete();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<class UElementData>> ElementDataAtlas;
};
