#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "XpBarWidget.generated.h"

class UXpComponent;
class UTextBlock;
class UProgressBar;

UCLASS()
class UXpBarWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void BindToXpComponent(TObjectPtr<UXpComponent> NewXpComponent);
	
protected:
	UFUNCTION()
	void Refresh();

	UPROPERTY(VisibleAnywhere)
	TWeakObjectPtr<UXpComponent> XpComponent;
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UProgressBar> XpBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UTextBlock> XpText;
	
};
