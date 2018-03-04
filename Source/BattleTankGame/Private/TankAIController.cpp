// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{

	Super::BeginPlay();

	ATank* PossessedTank = GetControlledTank();

	if (PossessedTank){
	
		UE_LOG(LogTemp, Warning, TEXT("AI tank: %s"), *PossessedTank->GetName());
	
	}

	else
	{

		UE_LOG(LogTemp, Warning, TEXT("AI does not posess a tank"));

	}

}

ATank* ATankAIController::GetControlledTank()
{

	return Cast<ATank>(GetPawn());

}
