#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"

#include "HealthBarComponent.generated.h"

class UHealthComponent;

UCLASS()
class PAISHO_API UHealthBarComponent : public UWidgetComponent
{
	GENERATED_BODY()
	
public:
	UHealthBarComponent();
	void Init(TObjectPtr<UHealthComponent> NewHealthComponent);

	UFUNCTION()
	void Refresh();

private:
	UPROPERTY(VisibleAnywhere)
	TWeakObjectPtr<UHealthComponent> HealthComponent;
};
