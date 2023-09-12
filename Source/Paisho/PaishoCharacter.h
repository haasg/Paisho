#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "PaishoCharacter.generated.h"

UCLASS()
class PAISHO_API APaishoCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

	APaishoCharacter(){};

	virtual void Tick(float DeltaSeconds) override;
	
};
