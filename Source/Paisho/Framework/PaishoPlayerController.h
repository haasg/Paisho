#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PaishoPlayerController.generated.h"

class UPlayerHudWidget;
class UHealthComponent;
class UXpComponent;

UCLASS()
class PAISHO_API APaishoPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	APaishoPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	
public:
	/* Player HUD */
	void BindHealthComponentToHud(TObjectPtr<UHealthComponent> HealthComponent);
	void BindXpComponentToHud(TObjectPtr<UXpComponent> XpComponent);
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UPlayerHudWidget> PlayerHud;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPlayerHudWidget> PlayerHudClass;
	/* Player HUD */
	
};
