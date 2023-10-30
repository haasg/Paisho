#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Paisho/Data/ElementType.h"
#include "Paisho/Data/LevelUpTypes.h"
#include "ElementalKnowledgeComponent.generated.h"



USTRUCT(BlueprintType)
struct FElementalKnowledgeLevel
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	EElement Element;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 Level;
};



UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PAISHO_API UElementalKnowledgeComponent : public UActorComponent
{
	GENERATED_BODY()

	/* Framework */
public:
	UElementalKnowledgeComponent();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
protected:
	virtual void BeginPlay() override;

	

	/* Knowledge */
public:
	void AddKnowledge(const EElement Element, int32 Amount);
	TArray<FElementLevelUpInfo> CalcElementLevelUpInfos(int32 Amount);
	TArray<FElementalKnowledgeLevel> GetKnowledge() const;
		
protected:
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly)
	TArray<FElementalKnowledgeLevel> ElementalKnowledge;
	
};
