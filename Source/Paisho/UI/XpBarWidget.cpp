#include "XpBarWidget.h"

#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Paisho/Character/XpComponent.h"
#include "Paisho/Util/DebugUtil.h"

void UXpBarWidget::BindToXpComponent(const TObjectPtr<UXpComponent> NewXpComponent)
{
	XpComponent = NewXpComponent;
	NewXpComponent->OnXpChanged.AddDynamic(this, &ThisClass::Refresh);
	Refresh();
}

void UXpBarWidget::Refresh()
{
	if(XpComponent.IsValid())
	{
		const float CurrentXp = XpComponent->CurrentXp();
		const int CurrentLevel = XpComponent->CurrentLevel();
		const int NextLevel = XpComponent->NextLevel();
		const float XpSinceLevelUp = XpComponent->XpSinceLevelUp();
		const float XpRequiredToBeCurrentLevel = XpComponent->TotalXpRequiredToBeCurrentLevel();
		const float XpRequiredForNextLevel = XpComponent->TotalXpRequiredForNextLevel();
		const float XpPercent = XpComponent->PercentThroughLevel();

		PRINT("CURRENT XP: %f", CurrentXp);
		PRINT("CURRENT LEVEL: %d", CurrentLevel);
		PRINT("NEXT LEVEL: %d", NextLevel);
		PRINT("XP SINCE LEVEL UP: %f", XpSinceLevelUp);
		PRINT("XP REQUIRED TO BE CURRENT LEVEL: %f", XpRequiredToBeCurrentLevel);
		PRINT("XP REQUIRED FOR NEXT LEVEL: %f", XpRequiredForNextLevel);
		PRINT("XP PERCENT: %f", XpPercent);

		
		//const float CurrentXp = XpComponent->CurrentXp();
		//const float XpPercent = XpComponent->PercentThroughLevel();
		const FText Text = FText::FromString(FString::Printf(TEXT("LEVEL: %d --- %d/%d"), CurrentLevel, FMath::RoundToInt(CurrentXp), FMath::RoundToInt(XpRequiredForNextLevel)));
		XpText->SetText(Text);
		XpBar->SetPercent(XpPercent);
	}
	else
	{
		ERROR("XpBarWidget refreshed without a valid XpComponent!");
	}
}


