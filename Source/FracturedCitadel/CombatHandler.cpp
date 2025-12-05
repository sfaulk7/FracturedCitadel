// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatHandler.h"
#include "FracturedCitadelCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"

#include "Algo/ForEach.h"

// Sets default values
ACombatHandler::ACombatHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create the CombatCamera
	CombatCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("CombatCamera"));
	CombatCamera->SetupAttachment(RootComponent);
	FVector CombatCameraLocation = FVector(-130, 80, 100);
	CombatCamera->SetRelativeLocation(CombatCameraLocation);
	// In blueprint (for some reason) this is different, instead of Pitch, Yaw, Roll, Blueprint has Roll, Pitch, Yaw 
	FRotator CombatCameraRotation = FRotator( -10, -10, 0);
	CombatCamera->SetRelativeRotation(CombatCameraRotation);

}

// Called when the game starts or when spawned
void ACombatHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACombatHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	
	for (size_t i = 0; i < EnemyArray.Num(); i++)
	{
		if (EnemyArray[i]->selected == true)
		{
			
		}
		
	}
}

