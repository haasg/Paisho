#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "XpBarWidget.generated.h"

class UTextBlock;
class UProgressBar;

UCLASS()
class UXpBarWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void Refresh(const float CurrentXp, const float MaxXp, const float XpPercent);
	
protected:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UProgressBar> XpBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UTextBlock> XpText;
	
};
