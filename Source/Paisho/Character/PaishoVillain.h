#pragma once

#include "PaperZDCharacter.h"
#include "PaishoVillain.generated.h"

class UHealthBarComponent;
class UHealthComponent;

UCLASS()
class PAISHO_API APaishoVillain : public APaperZDCharacter
{
	GENERATED_BODY()
public:

	APaishoVillain();

	virtual void BeginPlay() override;

	/* Combat Components */
	UPROPERTY(EditAnywhere, Category = "Combat")
	UHealthComponent* Health;

	UPROPERTY(EditAnywhere, Category = "Combat")
	UHealthBarComponent* HealthBar;
	/* End Combat Components */
};
