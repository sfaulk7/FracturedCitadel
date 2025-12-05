// Copyright Epic Games, Inc. All Rights Reserved.

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

AFracturedCitadelCharacter::AFracturedCitadelCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Create a selection box...
	SelectionBox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SelectionBox"));
	SelectionBox->SetupAttachment(RootComponent);
	SelectionBox->SetHiddenInGame(true);
	SelectionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	//Create the CombatCamera
	CombatCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("CombatCamera"));
	CombatCamera->SetupAttachment(RootComponent);
	FVector CombatCameraLocation = FVector(-130, 80, 100);
	CombatCamera->SetRelativeLocation(CombatCameraLocation);
	// In blueprint (for some reason) this is different, instead of Pitch, Yaw, Roll, Blueprint has Roll, Pitch, Yaw 
	FRotator CombatCameraRotation = FRotator( -10, -10, 0);
	CombatCamera->SetRelativeRotation(CombatCameraRotation);

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
	
	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AFracturedCitadelCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

