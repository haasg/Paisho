#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PaishoPlayerState.generated.h"

UCLASS()
class PAISHO_API APaishoPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetPlayerLocation(const FVector& NewLocation) { PlayerLocation = NewLocation; }

protected:
	UPROPERTY(Replicated, BlueprintReadOnly)
	FVector PlayerLocation;
};
