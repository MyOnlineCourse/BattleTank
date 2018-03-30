// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANKGAME_API ATankAIController : public AAIController
{
	GENERATED_BODY()
private:
		
	ATank* PlayersTank = nullptr;
	ATank* PosessedTank = nullptr;

	float AcceptanceRadius = 3000;
	
public:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
