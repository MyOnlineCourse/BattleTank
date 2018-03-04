// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{

	Super::BeginPlay();

	ATank* PossessedTank = GetControlledTank();
	ATank* PlayersTank = GetPlayerTank();

	if (PossessedTank){
	
		UE_LOG(LogTemp, Warning, TEXT("AI tank: %s"), *PossessedTank->GetName());
	
	}

	else
	{

		UE_LOG(LogTemp, Warning, TEXT("AI does not posess a tank"));

	}

	if (PlayersTank)
	{

		UE_LOG(LogTemp, Warning, TEXT("Found a tank to shoot at: %s"), *PlayersTank->GetName());

	}

	else
	{

		UE_LOG(LogTemp, Warning, TEXT("Could not find a tank to shoot at"));

	}

}

ATank* ATankAIController::GetControlledTank()
{

	return Cast<ATank>(GetPawn());

}

ATank* ATankAIController::GetPlayerTank() const
{

	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

}