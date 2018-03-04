// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TanksPlayerController.h"

void ATanksPlayerController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	AimAtCrosshair();

}

void ATanksPlayerController::AimAtCrosshair()
{

	if (!GetControlledTank()) { return; }

	else
	{

		FVector HitLocation;
		
		if (GetSightRayHitLocation(HitLocation))
		{
		}

	}

}

bool ATanksPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{

	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	
	FVector WorldDirection;

	if (GetLookDirection(ScreenLocation, WorldDirection))
	{

		//raycast out 
		FVector HitLocation;
		if(GetLookVectorHitLocation(HitLocation, WorldDirection))
		{
		
			//if it hits something, modify needed to reflect the end location and return true
			//otherwise break and return false
			UE_LOG(LogTemp, Warning, TEXT("End location: %s"), *HitLocation.ToString());
					
		}

	}

	return true;

}

bool ATanksPlayerController::GetLookVectorHitLocation(FVector& HitLocation, FVector LookDirection) const
{

	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * Range);

	FHitResult HitResult;

	FCollisionQueryParams additional;
	FCollisionResponseParams response;

	if(GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility/*, additional,response*/))
	{ 
	
		HitLocation = HitResult.Location;
		return true;
	
	}

	HitLocation = FVector(0.0);
	return false;

}

bool ATanksPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& WorldDirection) const
{

	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, WorldDirection);

}

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