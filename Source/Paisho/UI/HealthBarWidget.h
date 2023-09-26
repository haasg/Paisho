#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBarWidget.generated.h"

class UHealthComponent;
class UTextBlock;
class UProgressBar;

UCLASS()
class UHealthBarWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void BindToHealthComponent(TObjectPtr<UHealthComponent> NewHealthComponent);
	void Update(float CurrentHealth, float MaxHealth, float HealthPercent);

protected:
	UFUNCTION()
	void Refresh();

	UPROPERTY(VisibleAnywhere)
	TWeakObjectPtr<UHealthComponent> HealthComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* HealthBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* HealthText; 
};
