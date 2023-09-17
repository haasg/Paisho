#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBarWidget.generated.h"

class UProgressBar;
class UHealthBarComponent;
class UImage;

UCLASS()
class UHealthBarWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void Init(UHealthBarComponent* NewHealthBarComponent);
	void Refresh();

protected:

	UPROPERTY(VisibleAnywhere)
	TWeakObjectPtr<UHealthBarComponent> HealthBarComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* HealthBar;
};
