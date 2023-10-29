#pragma once

UENUM(BlueprintType)
enum class EElement :uint8
{
	Water UMETA(DisplayName = "Water"),
	Fire UMETA(DisplayName = "Fire"),
	Nature UMETA(DisplayName = "Nature"),
	Earth UMETA(DisplayName = "Earth"),
	Light UMETA(DisplayName = "Light"),
	Void UMETA(DisplayName = "Void"),
	
	Max UMETA(DisplayName = "DefaultMAX")
};
