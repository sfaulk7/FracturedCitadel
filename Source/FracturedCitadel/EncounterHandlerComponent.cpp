// Fill out your copyright notice in the Description page of Project Settings.


#include "EncounterHandlerComponent.h"

// Sets default values for this component's properties
UEncounterHandlerComponent::UEncounterHandlerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEncounterHandlerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEncounterHandlerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UEncounterHandlerComponent::TriggerEncounter(float encounterNumber)
{
	if (encounterNumber > 0)
	{
		if (encounterNumber <= emptyOdds)
		{
			EmptyEncounter();
			return 1;
		}
		else if (encounterNumber <= emptyOdds + enemyOdds)
		{
			EnemyEncounter();
			return 2;
		}
		else if (encounterNumber <= emptyOdds + enemyOdds + chestOdds)
		{
			ChestEncounter();
			return 3;
		}
		else if (encounterNumber <= emptyOdds + enemyOdds + chestOdds + healingOdds)
		{
			HealingEncounter();
			return 4;
		}
		else
		{
			// Print to screen in red for 5 seconds
			GEngine->AddOnScreenDebugMessage(
				-1,                      // Key (-1 means add new message)
				5.0f,                    // Display time in seconds
				FColor::Red,             // Text color
				"Failed to start encounter"); // Message text
		
			// Print to screen in red for 5 seconds
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.0f,
				FColor::Red,
				"ERROR 02: Invalid encounterNumber to TriggerEncounter in EncounterHandler. (NUMBER OVER 100)");
			return 0;
		}
	}
	else
	{
		// Print to screen in red for 5 seconds
		GEngine->AddOnScreenDebugMessage(
			-1,                      // Key (-1 means add new message)
			5.0f,                    // Display time in seconds
			FColor::Red,             // Text color
			"Failed to start encounter"); // Message text
		
		// Print to screen in red for 5 seconds
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.0f,
			FColor::Red,
			"ERROR 01: Invalid encounterNumber to TriggerEncounter in EncounterHandler (NUMBER BELOW 1)");
		return 0;
	}
}

void UEncounterHandlerComponent::EmptyEncounter()
{
	GEngine->AddOnScreenDebugMessage(
			-1,
			5.0f,
			FColor::Black,
			"Empty encounter");
}

void UEncounterHandlerComponent::EnemyEncounter()
{
	GEngine->AddOnScreenDebugMessage(
			-1,
			5.0f,
			FColor::Orange,
			"Enemy encounter");
}

void UEncounterHandlerComponent::ChestEncounter()
{
	GEngine->AddOnScreenDebugMessage(
			-1,
			5.0f,
			FColor::Yellow,
			"Chest encounter");
}

void UEncounterHandlerComponent::HealingEncounter()
{
	GEngine->AddOnScreenDebugMessage(
			-1,
			5.0f,
			FColor::Green,
			"HealingEncounter");
}

FVector2D UEncounterHandlerComponent::GetEnemySpawnDetails()
{
	float tempCred = creditCount/10;
	float levelCount = 1;

	while (tempCred > 5)
	{
		if (tempCred > 5)
		{
			tempCred = tempCred/10;
			levelCount++;
		}
		else
		{
			break;
		}
	}

	FVector2D SpawnsAndLevels(tempCred, levelCount);
	
	return SpawnsAndLevels;
}
