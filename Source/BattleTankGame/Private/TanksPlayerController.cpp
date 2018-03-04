// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TanksPlayerController.h"

void ATanksPlayerController::BeginPlay()
{

	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("BeginPlay called from the Tank's player controller."));

	ATank* PossessedTank = GetControlledTank();

	if (PossessedTank) 
	{
	
		FString TankName = PossessedTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Posessed tank name: %s"), *TankName);
	
	}

	else
	{

		UE_LOG(LogTemp, Warning, TEXT("No posessed tanks found..."));

	}

}

ATank* ATanksPlayerController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());

}