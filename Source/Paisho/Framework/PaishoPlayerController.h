#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PaishoPlayerController.generated.h"

UCLASS()
class PAISHO_API APaishoPlayerController : public APlayerController
{
	GENERATED_BODY()

	APaishoPlayerController();

	virtual void BeginPlay() override;


	/* Player HUD */
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UUserWidget> PlayerHud;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> PlayerHudClass;
	/* Player HUD */
	
};
