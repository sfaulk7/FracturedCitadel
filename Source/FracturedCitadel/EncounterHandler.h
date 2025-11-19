// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EncounterHandler.generated.h"

UCLASS()
class FRACTUREDCITADEL_API AEncounterHandler : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EncounterOdds, meta = (AllowPrivateAccess = "true"));
	float creditCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EncounterOdds, meta = (AllowPrivateAccess = "true"));
	float emptyOdds = 30;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EncounterOdds, meta = (AllowPrivateAccess = "true"));
	float enemyOdds = 30;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EncounterOdds, meta = (AllowPrivateAccess = "true"));
	float chestOdds = 30;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EncounterOdds, meta = (AllowPrivateAccess = "true"));
	float healingOdds = 10;
	
public:	
	// Sets default values for this actor's properties
	AEncounterHandler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Encounter are as followed
	// 1. An empty encounter, nothing happens
	// 2. An enemy encounter, triggers combat
	// 3. A chest encounter, opens chest for loot
	// 4. healing encounter, heals
	// The encounter number will be from 1-100 to simulate odds
	//UFUNCTION(BlueprintCallable, meta = (ALlowPrivateAccess = "true"))
	//void TriggerEncounter(float encounterNumber);
	
	//void EmptyEncounter();
	//void EnemyEncounter();
	//void ChestEncounter();
	//void HealingEncounter();

};
