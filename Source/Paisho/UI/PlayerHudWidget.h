﻿#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "PlayerHudWidget.generated.h"

class UTeammateWidget;
class UVerticalBox;
class UGameTimeWidget;
class UHealthBarWidget;
class UXpBarWidget;

UCLASS()
class UPlayerHudWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void BindToHealthComponent(TObjectPtr<class UHealthComponent> HealthComponent);
	void BindToXpComponent(TObjectPtr<class UXpComponent> XpComponent);
	void BindToTeam(TObjectPtr<class APaishoTeam> Team);
	void SetMatchGameTime(const int32 GameTime);

protected:
	UFUNCTION()
	void RefreshGameTime(const int32 GameTime);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UGameTimeWidget> GameTimeWidget;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UHealthBarWidget> HealthBarWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UXpBarWidget> XpBarWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UVerticalBox> TeammatesBox;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UTeammateWidget> TeammateWidgetClass;
	
	
};
