// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{

	//UE_LOG(LogTemp, Warning, TEXT("Barrel elevating..."));
	auto ElevationChange = FMath::Clamp(RelativeSpeed, -1.f, 1.f) * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds *-1;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	float NewElevation = FMath::Clamp(RawNewElevation, HighestBarrelAngle, LowestBarrelAngle);

	FRotator NewAngle = FRotator(NewElevation, 0.0, 0.0);

	SetRelativeRotation(NewAngle);

	//UE_LOG(LogTemp, Warning, TEXT("CLAMP: %f	MAX: %f	MIN: %f"), RawNewElevation, LowestBarrelAngle, HighestBarrelAngle);

}