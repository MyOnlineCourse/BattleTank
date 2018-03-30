// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay(){ Super::BeginPlay(); }

void ATankAIController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
		
	PosessedTank = Cast<ATank>(GetPawn());
	PlayersTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayersTank && PosessedTank) {

		PosessedTank->AimAt(PlayersTank->GetActorLocation(), false);
		PosessedTank->Fire();
		
		MoveToActor(PlayersTank, AcceptanceRadius);

	}

}