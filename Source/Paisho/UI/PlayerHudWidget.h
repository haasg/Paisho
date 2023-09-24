#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "PlayerHudWidget.generated.h"

class UGameTimeWidget;
class UHealthBarWidget;
class UXpBarWidget;

UCLASS()
class UPlayerHudWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void RefreshGameTime(const int32 GameTime);
	void RefreshHealth(const float CurrentHealth, const float MaxHealth, const float HealthPercent);
	void RefreshXp(const float CurrentXp, const float MaxXp, const float XpPercent);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UGameTimeWidget> GameTimeWidget;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UHealthBarWidget> HealthBarWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UXpBarWidget> XpBarWidget;

	
	
};
