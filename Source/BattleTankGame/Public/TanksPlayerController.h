// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TanksPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKGAME_API ATanksPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;
	
	virtual void Tick(float) override;
	virtual void BeginPlay() override;
	
	bool GetSightRayHitLocation(FVector&) const;

	void AimAtCrosshair();

private:

	bool GetLookDirection(FVector2D, FVector&) const;
	bool GetLookVectorHitLocation(FVector&, FVector) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = .50;
	
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = .50;
	
	UPROPERTY(EditAnywhere)
	float Range = 1000000.0;

};
