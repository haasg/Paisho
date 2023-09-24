#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "PlayerHud.generated.h"

class UGameTimeWidget;
class UHealthBarWidget;
class UXpBarWidget;

UCLASS()
class UPlayerHud : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void RefreshGameTime(const int32 GameTime);
	void RefreshHealth(const float CurrentHealth, const float MaxHealth, const float HealthPercent);
	void RefreshXp(const float CurrentXp, const float MaxXp, const float XpPercent);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UGameTimeWidget> GameTimeWidget;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UHealthBarWidget> HealthBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UXpBarWidget> XpBar;

	
	
};
