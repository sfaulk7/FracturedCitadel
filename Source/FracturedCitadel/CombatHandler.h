// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FracturedCitadelCharacter.h"
#include "FracturedCitadelEnemy.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CombatHandler.generated.h"

UCLASS()
class FRACTUREDCITADEL_API ACombatHandler : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EncounterOdds, meta = (AllowPrivateAccess = "true"));
	AFracturedCitadelCharacter* player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EncounterOdds, meta = (AllowPrivateAccess = "true"));
	TArray<AFracturedCitadelEnemy*> EnemyArray;

	/** Combat Camera */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CombatCamera;
	
public:	
	// Sets default values for this actor's properties
	ACombatHandler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
