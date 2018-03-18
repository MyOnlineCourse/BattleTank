// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankTurret.h"



void UTankTurret::Rotate(float delta, FRotator CurrentRotation, FRotator DesiredRotation, bool IsPlayer)
{

	float MovementChange = FMath::Clamp(delta, -5.f, 5.f) * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewRotation = RelativeRotation.Yaw + MovementChange;
	
	SetRelativeRotation(FRotator(0.0, RawNewRotation, 0.0));

}
