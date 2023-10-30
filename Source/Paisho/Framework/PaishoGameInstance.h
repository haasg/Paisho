#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Paisho/Data/ElementType.h"
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
	FORCEINLINE TMap<EElement, TObjectPtr<UElementData>> GetElementDataAtlas() const { return ElementDataAtlas; }
	TObjectPtr<UElementData> GetElementData(const EElement Element);
protected:
	void LoadDataAssets();
	void ElementAssetsLoadComplete();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<EElement, TObjectPtr<UElementData>> ElementDataAtlas;
};
