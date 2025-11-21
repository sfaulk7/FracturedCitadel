// Fill out your copyright notice in the Description page of Project Settings.


#include "FracturedCitadelEnemy.h"

#include "Components/CapsuleComponent.h"

// Sets default values
AFracturedCitadelEnemy::AFracturedCitadelEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a selection box...
	RootCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RootCapsule"));
	RootComponent = RootCapsule;
	

	// Create a selection box...
	SelectionBox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SelectionBox"));\
	SelectionBox->SetHiddenInGame(true);
}

// Called when the game starts or when spawned
void AFracturedCitadelEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFracturedCitadelEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

