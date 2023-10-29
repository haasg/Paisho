#include "ElementalKnowledgeComponent.h"

#include "Net/UnrealNetwork.h"


UElementalKnowledgeComponent::UElementalKnowledgeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UElementalKnowledgeComponent::BeginPlay()
{
	Super::BeginPlay();

	// get data from asset reg game instance and make a level 0 knowlege for each elemenet
}

void UElementalKnowledgeComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UElementalKnowledgeComponent, ElementalKnowledge);
}

