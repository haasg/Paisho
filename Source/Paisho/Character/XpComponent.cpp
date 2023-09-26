#include "XpComponent.h"

#include "Engine/CurveTable.h"

UXpComponent::UXpComponent(): XpInfoCache()
{
}

void UXpComponent::AddXp(const int32 Amount)
{
	bIsDirty = true;
	Xp += Amount;
	OnXpChanged.Broadcast();
}

float UXpComponent::CurrentXp() const
{
	return Xp;
}

float UXpComponent::XpRequiredForNextLevel()
{
	CleanCacheIfDirty();
	return XpInfoCache.XpRequiredForNextLevel;
}

float UXpComponent::XpRequiredToBeCurrentLevel()
{
	CleanCacheIfDirty();
	return XpInfoCache.XpRequiredToBeCurrentLevel;
}

float UXpComponent::PercentThroughLevel()
{
	CleanCacheIfDirty();
	return XpInfoCache.PercentThroughLevel;
}

float UXpComponent::XpSinceLevelUp()
{
	CleanCacheIfDirty();
	return XpInfoCache.XpSinceLevelUp;
}

int UXpComponent::CurrentLevel()
{
	CleanCacheIfDirty();
	return XpInfoCache.CurrentLevel;
}

int UXpComponent::NextLevel()
{
	return CurrentLevel() + 1;
}

void UXpComponent::CleanCacheIfDirty()
{
	if(bIsDirty == false)
	{
		return;
	}
	
	check(Xp >= 0);
	const FName RowName = "XpCurve";
	if(LevelCurveTable)
	{
		if(const FRichCurve* Curve = LevelCurveTable->FindRichCurve(RowName, FString("Getting Xp Level"), true))
		{
			const TArray<FRichCurveKey>& Keys = Curve->GetConstRefOfKeys();
			for(int32 i = 0; i < Keys.Num(); ++i)
			{
				// Check if the XP value is less than the value of this key
				if(Xp < Keys[i].Value)
				{
					XpInfoCache.CurrentLevel = i + 1;
					XpInfoCache.XpSinceLevelUp = i == 0 ? 0 : Xp - Keys[i - 1].Value;
					XpInfoCache.XpToLevelUp = Keys[i].Value - Xp;
					XpInfoCache.XpRequiredToBeCurrentLevel = i == 0 ? 0 : Keys[i - 1].Value;
					XpInfoCache.XpRequiredForNextLevel = Keys[i].Value;
					XpInfoCache.PercentThroughLevel = i == 0 ? XpInfoCache.XpSinceLevelUp : XpInfoCache.XpSinceLevelUp / (Keys[i].Value - Keys[i-1].Value);
					/* can remove these checks eventually */
					check(XpInfoCache.XpRequiredToBeCurrentLevel < XpInfoCache.XpRequiredForNextLevel);
					check(XpInfoCache.PercentThroughLevel >= 0.f && XpInfoCache.PercentThroughLevel <= 1.f);
					check(XpInfoCache.XpRequiredToBeCurrentLevel >= 0.f);
					check(XpInfoCache.XpRequiredForNextLevel >= 0.f);
					
					break;
				}
			}
		}
	}
	bIsDirty = false;
}
