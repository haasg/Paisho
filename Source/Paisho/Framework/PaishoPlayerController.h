#pragma once

#include "CoreMinimal.h"
#include "PaishoCommonController.h"
#include "..\Weapons\WeaponLevelUpInfo.h"
#include "PaishoPlayerController.generated.h"

class APaishoHero;
class APaishoTeam;
class UCommonActivatableWidget;
class UPlayerHudWidget;
class UHealthComponent;
class UXpComponent;

UCLASS()
class PAISHO_API APaishoPlayerController : public APaishoCommonController
{
	GENERATED_BODY()

	/* Lifetime */
public:
	APaishoPlayerController();
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void OnPossess(APawn* InPawn) override;
	


	/* Hero */
protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<APaishoHero> Hero;
	
	
	
	/* Team */
public:
	void PollJoinTeam();
	
protected:
	UPROPERTY(ReplicatedUsing = OnRep_Team, VisibleAnywhere)
	TObjectPtr<APaishoTeam> Team;

	UFUNCTION()
	void OnRep_Team();

	

	/* Level Up */
public:
	void CollectXpForTeam(int32 Amount);
	void AuthInitiateLevelUp(int Level);
	
protected:
	UFUNCTION(Client, Reliable) 
	void ClientInitiateLevelUp(const TArray<FWeaponLevelUpInfo>& LevelUpInfos); // Pops level up menu
	
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
