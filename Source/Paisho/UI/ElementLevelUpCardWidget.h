#pragma once

#include "CoreMinimal.h"
#include "LevelUpCardButtonBase.h"
#include "ElementLevelUpCardWidget.generated.h"

UCLASS()
class PAISHO_API UElementLevelUpCardWidget : public ULevelUpCardButtonBase
{
	GENERATED_BODY()

public:
	void SetElementLevelUpInfo(const FElementLevelUpInfo& InElementLevelUpInfo);
	virtual void Refresh() override;
	virtual void Reset() override;

protected:
	UPROPERTY(VisibleAnywhere)
	FElementLevelUpInfo ElementLevelUpInfo;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> ElementNameText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UImage> ElementImage;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> ElementLevelText;
	
		
};
