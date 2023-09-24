#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBarWidget.generated.h"

class UTextBlock;
class UProgressBar;

UCLASS()
class UHealthBarWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void Refresh(const float CurrentHealth, const float MaxHealth, const float HealthPercent);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* HealthBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* HealthText; 
};
