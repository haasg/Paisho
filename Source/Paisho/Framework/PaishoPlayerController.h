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
	void InitiateLevelUp(int Level);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	void PollInit();
	

	/* Team */
protected:
	UPROPERTY(ReplicatedUsing = OnRep_Team, VisibleAnywhere)
	TObjectPtr<APaishoTeam> Team;

	UFUNCTION()
	void OnRep_Team();

	

	/* Level Up */
protected:
	UFUNCTION(Client, Reliable) 
	void ClientInitiateLevelUp(); // Pops level up menu
	
	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerCompleteLevelUp(); // Tells the server a selection has been made
public:	
	UPROPERTY(Replicated)
	bool bIsWaitingForLevelUpInput = false;



	/* Sync Time Between Server and Client */
public:
	float GetServerTime();
	virtual void ReceivedPlayer() override; // Sync with server clock as soon as possible
	
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
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCommonActivatableWidget> LevelUpMenu;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UCommonActivatableWidget> LevelUpMenuClass;
	
};
