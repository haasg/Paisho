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

	for (uint8 i = 0; i < static_cast<uint8>(EElement::Max); i++)
	{
		const EElement Element = static_cast<EElement>(i);
		FElementalKnowledgeLevel Knowledge = FElementalKnowledgeLevel{Element, 0};
		ElementalKnowledge.Add(Knowledge);
	}
}

void UElementalKnowledgeComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UElementalKnowledgeComponent, ElementalKnowledge);
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

