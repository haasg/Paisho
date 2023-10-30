#include "LevelUpSelectorWidget.h"

#include "ElementLevelUpCardWidget.h"
#include "LevelUpCardButtonBase.h"
#include "WeaponLevelUpCardWidget.h"
#include "Components/HorizontalBox.h"
#include "Paisho/Framework/PaishoPlayerController.h"
#include "Paisho/Util/DebugUtil.h"


void ULevelUpSelectorWidget::Init(const TArray<FWeaponLevelUpInfo>& InWeaponLevelUpInfos)
{
	CardBox->ClearChildren();
	LevelUpCardButtons.Empty();
	for(auto& LevelUpInfo : InWeaponLevelUpInfos)
	{
		const TObjectPtr<ULevelUpCardButtonBase> LevelUpCardButton = CreateWidget<ULevelUpCardButtonBase>(GetWorld(), WeaponLevelUpCardButtonClass);
		if(TObjectPtr<UWeaponLevelUpCardWidget> WeaponLevelUpCard = Cast<UWeaponLevelUpCardWidget>(LevelUpCardButton))
		{
			WeaponLevelUpCard->SetWeaponLevelUpInfo(LevelUpInfo);
			WeaponLevelUpCard->ParentWidget = this;
			WeaponLevelUpCard->Index = LevelUpCardButtons.Num();
			LevelUpCardButtons.Add(WeaponLevelUpCard);
			CardBox->AddChild(WeaponLevelUpCard);
		} ELSE_ERROR("Level up widget was of wrong type, won't be setup properly")
	}
}

void ULevelUpSelectorWidget::Init(const TArray<FElementLevelUpInfo>& InElementLevelUpInfos)
{
	CardBox->ClearChildren();
	LevelUpCardButtons.Empty();
	for(auto& ElementLevelUpInfo : InElementLevelUpInfos)
	{
		const TObjectPtr<ULevelUpCardButtonBase> LevelUpCardButton = CreateWidget<ULevelUpCardButtonBase>(GetWorld(), ElementLevelUpCardButtonClass);
		if(TObjectPtr<UElementLevelUpCardWidget> ElementLevelUpCard = Cast<UElementLevelUpCardWidget>(LevelUpCardButton))
		{
			ElementLevelUpCard->SetElementLevelUpInfo(ElementLevelUpInfo);
			ElementLevelUpCard->ParentWidget = this;
			ElementLevelUpCard->Index = LevelUpCardButtons.Num();
			LevelUpCardButtons.Add(ElementLevelUpCard);
			CardBox->AddChild(ElementLevelUpCard);
		} ELSE_ERROR("Level up widget was of wrong type, won't be setup properly")
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
