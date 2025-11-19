// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EncounterHandlerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FRACTUREDCITADEL_API UEncounterHandlerComponent : public UActorComponent
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EncounterOdds, meta = (AllowPrivateAccess = "true"));
	float emptyOdds = 30;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EncounterOdds, meta = (AllowPrivateAccess = "true"));
	float enemyOdds = 30;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EncounterOdds, meta = (AllowPrivateAccess = "true"));
	float chestOdds = 30;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EncounterOdds, meta = (AllowPrivateAccess = "true"));
	float healingOdds = 10;
	
public:	
	// Sets default values for this component's properties
	UEncounterHandlerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Encounter are as followed
	// 1. An empty encounter, nothing happens
	// 2. An enemy encounter, triggers combat
	// 3. A chest encounter, opens chest for loot
	// 4. healing encounter, heals
	// The encounter number will be from 1-100 to simulate odds
	UFUNCTION(BlueprintCallable, meta = (ALlowPrivateAccess = "true"))
	void TriggerEncounter(float encounterNumber);
	
	void EmptyEncounter();
	void EnemyEncounter();
	void ChestEncounter();
	void HealingEncounter();
};
