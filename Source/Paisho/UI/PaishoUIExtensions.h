#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "PaishoUIExtensions.generated.h"

enum class EWidgetLayer : uint8;
class UCommonActivatableWidget;

UCLASS()
class UPaishoUIExtensions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UPaishoUIExtensions() { }

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Global UI Extensions")
	static UCommonActivatableWidget* PushContentToLayer_ForPlayer(APlayerController* PlayerController,
	EWidgetLayer LayerName, TSubclassOf<UCommonActivatableWidget> WidgetClass);

	
};
