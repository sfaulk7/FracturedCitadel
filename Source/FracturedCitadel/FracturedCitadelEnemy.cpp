// Fill out your copyright notice in the Description page of Project Settings.


#include "FracturedCitadelEnemy.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AFracturedCitadelEnemy::AFracturedCitadelEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a selection box...
	RootCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RootCapsule"));
	RootComponent = RootCapsule;

	// Create a selection box...
	SelectionBox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SelectionBox"));
	SelectionBox->SetupAttachment(RootComponent);
	SelectionBox->SetHiddenInGame(true);
	SelectionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	//Create the SpringArm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bDoCollisionTest = false;
	SpringArm->TargetArmLength = -350;
	
	//Create the SelectedCamera
	SelectedCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("SelectedCamera"));
	// In blueprint (for some reason) this is different, instead of Pitch, Yaw, Roll, Blueprint has Roll, Pitch, Yaw 
	FRotator SelectedCameraRotation = FRotator( 5, 180, 0);
	SelectedCamera->SetRelativeRotation(SelectedCameraRotation);
	SelectedCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	
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

void AFracturedCitadelEnemy::SetEnemyLevel(int level)
{
	//Adjust stats based on level
	enemyMaxHealth = (enemyMaxHealth + level) * (level + (level / 2));
	enemyHealth = enemyMaxHealth;
	enemySpeed = enemySpeed + level;
}

