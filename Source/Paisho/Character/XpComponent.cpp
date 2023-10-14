#include "XpComponent.h"

#include "Engine/CurveTable.h"
#include "Paisho/Util/DebugUtil.h"

UXpComponent::UXpComponent(): XpInfoCache()
{
}

void UXpComponent::AddXp(const int32 Amount)
{
	const int PreAddXpLevel = CurrentLevel();
	bIsDirty = true;
	Xp += Amount;
	OnXpChanged.Broadcast();
	const int PostAddXpLevel = CurrentLevel();
	
	check(PostAddXpLevel >= PreAddXpLevel);
	if(PreAddXpLevel != PostAddXpLevel)
	{
		OnLevelUp.Broadcast(PostAddXpLevel);
	}
}

float UXpComponent::CurrentXp() const
{
	return Xp;
}

float UXpComponent::TotalXpRequiredForNextLevel()
{
	CleanCacheIfDirty();
	return XpInfoCache.TotalXpRequiredForNextLevel;
}

float UXpComponent::TotalXpRequiredToBeCurrentLevel()
{
	CleanCacheIfDirty();
	return XpInfoCache.TotalXpRequiredToBeCurrentLevel;
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

float UXpComponent::XpToLevelUp()
{
	CleanCacheIfDirty();
	return XpInfoCache.XpToLevelUp;
}

float UXpComponent::TotalXpRequiredToCompleteCurrentLevel()
{
	CleanCacheIfDirty();
	return XpInfoCache.TotalXpRequiredForNextLevel - XpInfoCache.TotalXpRequiredToBeCurrentLevel; 
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
		if(const FSimpleCurve* Curve = LevelCurveTable->FindSimpleCurve(RowName, FString("Getting Xp Level"), true))
		{
			const TArray<FSimpleCurveKey>& Keys = Curve->GetConstRefOfKeys();
			for(int32 i = 0; i < Keys.Num(); ++i)
			{
				// Check if the XP value is less than the value of this key
				if(Xp < Keys[i].Value)
				{
					XpInfoCache.CurrentLevel = i;
					XpInfoCache.XpSinceLevelUp = i == 0 ? 0 : Xp - Keys[i - 1].Value;
					XpInfoCache.XpToLevelUp = Keys[i].Value - Xp;
					XpInfoCache.TotalXpRequiredToBeCurrentLevel = i == 0 ? 0 : Keys[i - 1].Value;
					XpInfoCache.TotalXpRequiredForNextLevel = Keys[i].Value;
					XpInfoCache.PercentThroughLevel = i == 0 ? XpInfoCache.XpSinceLevelUp : XpInfoCache.XpSinceLevelUp / (Keys[i].Value - Keys[i-1].Value);
					/* can remove these checks eventually */
					check(XpInfoCache.TotalXpRequiredToBeCurrentLevel < XpInfoCache.TotalXpRequiredForNextLevel);
					check(XpInfoCache.PercentThroughLevel >= 0.f && XpInfoCache.PercentThroughLevel <= 1.f);
					check(XpInfoCache.TotalXpRequiredToBeCurrentLevel >= 0.f);
					check(XpInfoCache.TotalXpRequiredForNextLevel >= 0.f);
					
					break;
				}
			}
		}
	}
	bIsDirty = false;
}
