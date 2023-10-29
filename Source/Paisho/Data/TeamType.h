#pragma once

UENUM(BlueprintType)
enum class ETeam : uint8
{
	RedTeam UMETA(DisplayName = "RedTeam"),
	BlueTeam UMETA(DisplayName = "BlueTeam"),
	NoTeam UMETA(DisplayName = "NoTeam"),

	Max UMETA(DisplayName = "DefaultMAX")
};
