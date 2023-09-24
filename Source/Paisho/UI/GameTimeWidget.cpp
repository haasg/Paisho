#include "GameTimeWidget.h"

#include "Components/TextBlock.h"

void UGameTimeWidget::Refresh(const int32 GameTime)
{
	const int32 Minutes = static_cast<int32>(GameTime / 60.0f);
	const int32 Seconds = static_cast<int32>(FMath::Fmod(GameTime, 60.0f));
	
	const FString TimeString = FString::Printf(TEXT("%02d:%02d"), Minutes, Seconds);
	GameTimeText->SetText(FText::FromString(TimeString));
}
