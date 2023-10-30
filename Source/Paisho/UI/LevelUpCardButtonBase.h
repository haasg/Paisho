#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Paisho/Data/LevelUpTypes.h"
#include "LevelUpCardButtonBase.generated.h"


class ULevelUpSelectorWidget;
class UCommonTextBlock;
class UImage;
class UCommonActivatableWidget;

UCLASS(Abstract)
class PAISHO_API ULevelUpCardButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()

	/* Framework */
public:
	virtual void Refresh();
	virtual void Reset();
	virtual void NativeOnPressed() override;

	UPROPERTY()
	int32 Index;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<ULevelUpSelectorWidget> ParentWidget;
};
