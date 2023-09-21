#include "XpComponent.h"

#include "Engine/CurveTable.h"

UXpComponent::UXpComponent()
{
}

float UXpComponent::CurrentXp() const
{
	return Xp;
}

float UXpComponent::XpToNextLevel() const
{
}

float UXpComponent::XpFromPreviousLevel() const
{
}

int UXpComponent::Level() const
{
	FName RowName = "XpCurve";
	if(LevelCurveTable)
	{
		FRealCurve* Curve = LevelCurveTable->FindCurve(RowName, FString("Getting Xp Level"), true);
		
	}
}
