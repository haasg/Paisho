#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "PaishoAssetManager.generated.h"

UCLASS()
class PAISHO_API UPaishoAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	UPaishoAssetManager() {}
	static UPaishoAssetManager& Get();

	static const FPrimaryAssetType HeroType;
	static const FPrimaryAssetType VillainType;
	static const FPrimaryAssetType WeaponType;
	static const FPrimaryAssetType ElementData;
	
};
