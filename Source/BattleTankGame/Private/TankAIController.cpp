// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{

	Super::BeginPlay();

	PosessedTank = GetControlledTank();
	PlayersTank = GetPlayerTank();

	if (PosessedTank){
	
		UE_LOG(LogTemp, Warning, TEXT("AI tank: %s"), *PosessedTank->GetName());
	
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

void ATankAIController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	AimAt();

}

void ATankAIController::AimAt() const
{

	if (GetPlayerTank())
	{

		PosessedTank->AimAt(GetPlayerTank()->GetActorLocation(), false);

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