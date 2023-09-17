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
	void Init(UHealthComponent* NewHealthComponent);

	float CalcHealthPercent();

private:
	UPROPERTY(VisibleAnywhere)
	UHealthComponent* HealthComponent;
};
