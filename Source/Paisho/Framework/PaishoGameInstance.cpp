#include "PaishoGameInstance.h"

#include "PaishoAssetManager.h"
#include "Paisho/Data/ElementData.h"
#include "Paisho/Util/DebugUtil.h"

void UPaishoGameInstance::Init()
{
	Super::Init();

	LoadDataAssets();
}

TObjectPtr<UElementData> UPaishoGameInstance::GetElementData(const EElement Element) 
{
	const TObjectPtr<UElementData>* MapElement = ElementDataAtlas.Find(Element);
	if(MapElement == nullptr)
	{
		PRINT("FOUND NULL");
		return nullptr;
	}
	PRINT("FOUND NOT NULL");
	return *MapElement;
}

void UPaishoGameInstance::LoadDataAssets()
{
	LOG("PAISHO STARTUP: Initiating Asset Loading");
	UPaishoAssetManager& AssetManager = UPaishoAssetManager::Get();

	TArray<FName> CurrentLoadState;
	CurrentLoadState.Add(FName("Game"));

	TArray<FPrimaryAssetId> ElementIdList;
	AssetManager.GetPrimaryAssetIdList(UPaishoAssetManager::ElementData, ElementIdList);
	const FStreamableDelegate ElementLoadedDelegate = FStreamableDelegate::CreateUObject(this, &UPaishoGameInstance::ElementAssetsLoadComplete);
	AssetManager.LoadPrimaryAssets(ElementIdList, CurrentLoadState, ElementLoadedDelegate);
}

void UPaishoGameInstance::ElementAssetsLoadComplete()
{
	LOG("PAISHO STARTUP: ItemAssetsLoadComplete");
	const UPaishoAssetManager& AssetManager = UPaishoAssetManager::Get();
	
	TArray<FPrimaryAssetId> ElementIdList;
	AssetManager.GetPrimaryAssetIdList(UPaishoAssetManager::ElementData, ElementIdList);
	LOG("PAISHO STARTUP: Loaded (%d) Item Assets", ElementIdList.Num());

	for(const FPrimaryAssetId& ElementId : ElementIdList)
	{
		if (UElementData* ElementData = Cast<UElementData>(AssetManager.GetPrimaryAssetObject(ElementId)))
		{
			VERBOSE("LOADED ITEM ASSET: %s", *ElementData->GetPrimaryAssetId().ToString());
			ElementDataAtlas.Add(ElementData->Element, ElementData);
		}
		else
		{
			ERROR("ITEM ASSET FAILED TO LOAD: %s", *ElementId.ToString());
		}
	}
}
