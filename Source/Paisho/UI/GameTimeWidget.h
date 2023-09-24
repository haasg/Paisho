#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameTimeWidget.generated.h"

class UTextBlock;

UCLASS()
class UGameTimeWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void Refresh(const int32 GameTime);
	
protected:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UTextBlock> GameTimeText;
};
