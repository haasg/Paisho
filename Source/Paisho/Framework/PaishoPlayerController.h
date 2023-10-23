#pragma once

#include "CoreMinimal.h"
#include "PaishoCommonController.h"
#include "PaishoPlayerController.generated.h"

class APaishoTeam;
class UCommonActivatableWidget;
class UPlayerHudWidget;
class UHealthComponent;
class UXpComponent;

UCLASS()
class PAISHO_API APaishoPlayerController : public APaishoCommonController
{
	GENERATED_BODY()
	
public:
	APaishoPlayerController();
	
	void CollectXpForTeam(int32 Amount);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	void PollInit();
	
	/* Sync Time Between Server and Client */
public:
	float GetServerTime();
	virtual void ReceivedPlayer() override; // Sync with server clock as soon as possible

protected:
	UPROPERTY(ReplicatedUsing = OnRep_Team, VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<APaishoTeam> Team;

	UFUNCTION()
	void OnRep_Team();
protected:
	UFUNCTION(Server, Reliable)
	void ServerRequestServerTime(float TimeOfClientRequest); // Client -> Server

	UFUNCTION(Client, Reliable)
	void ClientReportServerTime(float TimeOfClientRequest, float TimeServerReceivedClientRequest); // Server -> Client

	UPROPERTY(EditAnywhere, Category = "Time Sync")
	float TimeSyncFrequency = 5.0; // How often to recalibrate client server delta

	void PollClientServerTimeSync(float DeltaSeconds);
	float ClientServerDelta = 0.0; // Current approx time delta between client and server
	float TimeSinceLastSync = 0.0; // How long since last time sync

	/* Player HUD */
public:
	void BindHealthComponentToHud(TObjectPtr<UHealthComponent> HealthComponent);
	void BindXpComponentToHud(TObjectPtr<UXpComponent> XpComponent);
	void SetMatchGameTime(const float GameTime);
	void BindToLevelUp(TObjectPtr<UXpComponent> XpComponent);
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UPlayerHudWidget> PlayerHud;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPlayerHudWidget> PlayerHudClass;


	UFUNCTION()
	void ShowLevelUpMenu(int NewLevel);
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCommonActivatableWidget> LevelUpMenu;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UCommonActivatableWidget> LevelUpMenuClass;
	
};
