#include "LevelUpSelectorWidget.h"

#include "LevelUpCardButtonBase.h"
#include "WeaponLevelUpCardWidget.h"
#include "Components/HorizontalBox.h"
#include "Paisho/Framework/PaishoPlayerController.h"
#include "Paisho/Util/DebugUtil.h"


void ULevelUpSelectorWidget::Init(const TArray<FWeaponLevelUpInfo>& InWeaponLevelUpInfos)
{
	for(auto& LevelUpInfo : InWeaponLevelUpInfos)
	{
		const TObjectPtr<ULevelUpCardButtonBase> LevelUpCardButton = CreateWidget<ULevelUpCardButtonBase>(GetWorld(), LevelUpCardButtonClass);
		if(TObjectPtr<UWeaponLevelUpCardWidget> WeaponLevelUpCard = Cast<UWeaponLevelUpCardWidget>(LevelUpCardButton))
		{
			WeaponLevelUpCard->SetWeaponLevelUpInfo(LevelUpInfo);
			WeaponLevelUpCard->ParentWidget = this;
			WeaponLevelUpCard->Index = LevelUpCardButtons.Num();
			LevelUpCardButtons.Add(WeaponLevelUpCard);
			CardBox->AddChild(WeaponLevelUpCard);
		}
		// DO ELEMNET CARD HERE TODO: 

	}
}

void ULevelUpSelectorWidget::Init(const TArray<FElementLevelUpInfo>& InElementLevelUpInfos)
{
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
