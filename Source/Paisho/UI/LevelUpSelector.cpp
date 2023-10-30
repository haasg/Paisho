#include "LevelUpSelector.h"

#include "LevelUpCardButton.h"
#include "Components/HorizontalBox.h"
#include "Paisho/Framework/PaishoPlayerController.h"
#include "Paisho/Util/DebugUtil.h"


void ULevelUpSelector::Init(const TArray<FWeaponLevelUpInfo>& InWeaponLevelUpInfos)
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

void ULevelUpSelector::ButtonPressed(int32 Index)
{
	for(auto& Button : LevelUpCardButtons)
	{
		if(Index != Button->Index)
		{
			Button->Reset();
		}
	}
	TObjectPtr<APaishoPlayerController> PC = Cast<APaishoPlayerController>(GetOwningPlayer());
	if(PC)
	{
		PC->ServerCompleteLevelUp(Index);
	}
}
