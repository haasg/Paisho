#include "LevelUpSelectorWidget.h"

#include "LevelUpCardButton.h"
#include "Components/HorizontalBox.h"
#include "Paisho/Framework/PaishoPlayerController.h"
#include "Paisho/Util/DebugUtil.h"


void ULevelUpSelectorWidget::Init(const TArray<FWeaponLevelUpInfo>& InWeaponLevelUpInfos)
{
	for(auto& LevelUpInfo : InWeaponLevelUpInfos)
	{
		const TObjectPtr<ULevelUpCardButton> LevelUpCardButton = CreateWidget<ULevelUpCardButton>(GetWorld(), LevelUpCardButtonClass);
		LevelUpCardButton->SetWeaponLevelUpInfo(LevelUpInfo);
		LevelUpCardButton->ParentWidget = this;
		LevelUpCardButton->Index = LevelUpCardButtons.Num();
		LevelUpCardButtons.Add(LevelUpCardButton);
		CardBox->AddChild(LevelUpCardButton);
	}
}

void ULevelUpSelectorWidget::ButtonPressed(const int32 Index)
{
	for(const auto& Button : LevelUpCardButtons)
	{
		if(Index != Button->Index)
		{
			Button->Reset();
		}
	}
	if(const TObjectPtr<APaishoPlayerController> PC = Cast<APaishoPlayerController>(GetOwningPlayer()))
	{
		PC->ServerCompleteLevelUp(Index);
	}
}
