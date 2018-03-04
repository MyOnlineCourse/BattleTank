// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKGAME_API ATankAIController : public AAIController
{
	GENERATED_BODY()
private:
		
	ATank* GetControlledTank();
	ATank* GetPlayerTank() const;
	
public:
	
	virtual void BeginPlay() override;
	
};
