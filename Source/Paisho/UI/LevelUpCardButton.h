#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "LevelUpCardButton.generated.h"


class UCommonActivatableWidget;

UCLASS(Abstract)
class PAISHO_API ULevelUpCardButton : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCommonActivatableWidget> ParentWidget;
};
