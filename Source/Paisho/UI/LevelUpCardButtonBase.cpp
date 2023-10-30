#include "LevelUpCardButtonBase.h"

#include "CommonTextBlock.h"
#include "LevelUpSelectorWidget.h"
#include "Components/Image.h"
#include "Paisho/Data/WeaponData.h"


void ULevelUpCardButtonBase::Refresh() {}
void ULevelUpCardButtonBase::Reset() {}

void ULevelUpCardButtonBase::NativeOnPressed()
{
	Super::NativeOnPressed();

	SetColorAndOpacity(FLinearColor::Blue);
	ParentWidget->ButtonPressed(Index);
}
