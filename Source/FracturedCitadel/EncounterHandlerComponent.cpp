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

void UEncounterHandlerComponent::TriggerEncounter(float encounterNumber)
{
	if (encounterNumber > 0)
	{
		if (encounterNumber <= emptyOdds)
		{
			EmptyEncounter();
		}
		else if (encounterNumber <= emptyOdds + enemyOdds)
		{
			EnemyEncounter();
		}
		else if (encounterNumber <= emptyOdds + enemyOdds + chestOdds)
		{
			ChestEncounter();
		}
		else if (encounterNumber <= emptyOdds + enemyOdds + chestOdds + healingOdds)
		{
			HealingEncounter();
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
