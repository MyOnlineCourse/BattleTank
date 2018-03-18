// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankTurret.h"



void UTankTurret::Rotate(float delta, FRotator CurrentRotation, FRotator DesiredRotation, bool IsPlayer)
{

	float MovementChange = FMath::Clamp(delta, -5.f, 5.f) * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewRotation = RelativeRotation.Yaw + MovementChange;
	
	FRotator NewRotation = FRotator(0.0, RawNewRotation, 0.0);

	SetRelativeRotation(FRotator(0.0, NewRotation.Yaw, 0.0));

	if (IsPlayer){ 	}

	/*
	if (CurrentRotation.Yaw != DesiredRotation.Yaw)
	{
			
		//SetRelativeRotation(NewRotation);

	}
	*/
	//SetRelativeRotation(FRotator(0.0, DesiredRotation.Yaw - 180, 0.0));

}
