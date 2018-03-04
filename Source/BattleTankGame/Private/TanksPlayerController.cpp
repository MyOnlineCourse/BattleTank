// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TanksPlayerController.h"

ATank* ATanksPlayerController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());

}


