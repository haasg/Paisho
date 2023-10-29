#include "ElementalKnowledgeComponent.h"

#include "Net/UnrealNetwork.h"
#include "Paisho/Framework/PaishoGameInstance.h"
#include "Paisho/Data/ElementData.h"
#include "Paisho/Util/DebugUtil.h"


UElementalKnowledgeComponent::UElementalKnowledgeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UElementalKnowledgeComponent::BeginPlay()
{
	Super::BeginPlay();

	/* Initialize elemental knowledge to 0 */
	if(const TObjectPtr<UPaishoGameInstance> GI = GetWorld()->GetGameInstance<UPaishoGameInstance>())
	{
		for(const auto& ElementData : GI->GetElementDataAtlas())
		{
			FElementalKnowledgeLevel Knowledge;
			Knowledge.Element = ElementData->Element;
			Knowledge.Level = 0;
			ElementalKnowledge.Add(Knowledge);
		}
	} ELSE_ERROR("Invalid game instance when initalizing elemental knowledge component")

}

void UElementalKnowledgeComponent::AddKnowledge(const EElement Element, const int32 Amount)
{
	for(auto& Knowledge : ElementalKnowledge)
	{
		if(Knowledge.Element == Element)
		{
			Knowledge.Level += Amount;
			return;
		}
	}
}

TArray<FElementalKnowledgeLevel> UElementalKnowledgeComponent::GetKnowledge() const
{
	return ElementalKnowledge;
}

void UElementalKnowledgeComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UElementalKnowledgeComponent, ElementalKnowledge);
}

