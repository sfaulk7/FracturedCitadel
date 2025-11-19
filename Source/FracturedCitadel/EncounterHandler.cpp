// Fill out your copyright notice in the Description page of Project Settings.

#include "EncounterHandler.h"
#include "Engine/Engine.h" // Needed for GEngine
#include "Engine/World.h"

// Sets default values
AEncounterHandler::AEncounterHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEncounterHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEncounterHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// void AEncounterHandler::TriggerEncounter(float encounterNumber)
// {
// 	if (encounterNumber > 0)
// 	{
// 		if (encounterNumber <= emptyOdds)
// 		{
// 			EmptyEncounter();
// 		}
// 		else if (encounterNumber <= emptyOdds + enemyOdds)
// 		{
// 			EnemyEncounter();
// 		}
// 		else if (encounterNumber <= emptyOdds + enemyOdds + chestOdds)
// 		{
// 			ChestEncounter();
// 		}
// 		else if (encounterNumber <= emptyOdds + enemyOdds + chestOdds + healingOdds)
// 		{
// 			HealingEncounter();
// 		}
// 		else
// 		{
// 			// Print to screen in red for 5 seconds
// 			GEngine->AddOnScreenDebugMessage(
// 				-1,                      // Key (-1 means add new message)
// 				5.0f,                    // Display time in seconds
// 				FColor::Red,             // Text color
// 				"Failed to start encounter"); // Message text
// 		
// 			// Print to screen in red for 5 seconds
// 			GEngine->AddOnScreenDebugMessage(
// 				-1,
// 				5.0f,
// 				FColor::Red,
// 				"ERROR 02: Invalid encounterNumber to TriggerEncounter in EncounterHandler. (NUMBER OVER 100)");
// 		}
// 	}
// 	else
// 	{
// 		// Print to screen in red for 5 seconds
// 		GEngine->AddOnScreenDebugMessage(
// 			-1,                      // Key (-1 means add new message)
// 			5.0f,                    // Display time in seconds
// 			FColor::Red,             // Text color
// 			"Failed to start encounter"); // Message text
// 		
// 		// Print to screen in red for 5 seconds
// 		GEngine->AddOnScreenDebugMessage(
// 			-1,
// 			5.0f,
// 			FColor::Red,
// 			"ERROR 01: Invalid encounterNumber to TriggerEncounter in EncounterHandler (NUMBER BELOW 1)");
// 	}
// }
//
// void AEncounterHandler::EmptyEncounter()
// {
// 	GEngine->AddOnScreenDebugMessage(
// 			-1,
// 			5.0f,
// 			FColor::Black,
// 			"Empty encounter");
// }
//
// void AEncounterHandler::EnemyEncounter()
// {
// 	GEngine->AddOnScreenDebugMessage(
// 			-1,
// 			5.0f,
// 			FColor::Orange,
// 			"Enemy encounter");
// }
//
// void AEncounterHandler::ChestEncounter()
// {
// 	GEngine->AddOnScreenDebugMessage(
// 			-1,
// 			5.0f,
// 			FColor::Yellow,
// 			"Chest encounter");
// }
//
// void AEncounterHandler::HealingEncounter()
// {
// 	GEngine->AddOnScreenDebugMessage(
// 			-1,
// 			5.0f,
// 			FColor::Green,
// 			"HealingEncounter");
// }
//
