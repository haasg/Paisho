#include "PaishoAssetManager.h"

#include "Paisho/Util/DebugUtil.h"

const FPrimaryAssetType	UPaishoAssetManager::HeroType = TEXT("HeroData");
const FPrimaryAssetType	UPaishoAssetManager::VillainType = TEXT("VillainData");
const FPrimaryAssetType	UPaishoAssetManager::WeaponType = TEXT("WeaponData");
const FPrimaryAssetType	UPaishoAssetManager::ElementData = TEXT("ElementData");

UPaishoAssetManager& UPaishoAssetManager::Get()
{
	if (UPaishoAssetManager* Manager = Cast<UPaishoAssetManager>(GEngine->AssetManager))
	{
		return *Manager;
	}
	else
	{
		ERROR("Invalid AssetManager in DefaultEngine.ini, must be UIounAssetManager!");
		return *NewObject<UPaishoAssetManager>(); // never calls this
	}
}