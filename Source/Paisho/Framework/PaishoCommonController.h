#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "PaishoCommonController.generated.h"

class UBaseWidget;

UCLASS()
class PAISHO_API APaishoCommonController : public APlayerController
{
	GENERATED_BODY()
public:
	APaishoCommonController();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UBaseWidget> BaseWidget;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UBaseWidget> BaseWidgetClass;
};
