#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "TeammateWidget.generated.h"

class APaishoHero;
class UHealthBarWidget;
class UCommonTextBlock;

UCLASS()
class PAISHO_API UTeammateWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	void BindToHero(const TObjectPtr<APaishoHero> Hero);

protected:
	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	TObjectPtr<UTexture2D> ProfilePicture;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> NameText;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	TObjectPtr<UHealthBarWidget> HealthBarWidget;
};
