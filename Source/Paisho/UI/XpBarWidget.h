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
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UProgressBar> XpBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UTextBlock> XpText;
	
};
