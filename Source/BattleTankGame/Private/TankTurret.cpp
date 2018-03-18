// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankTurret.h"



void UTankTurret::Rotate(float delta, FRotator CurrentRotation, FRotator DesiredRotation, bool IsPlayer)
{

	float MovementChange = FMath::Clamp(delta, -5.f, 5.f) * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewRotation = RelativeRotation.Yaw + MovementChange;
	
	FRotator NewRotation = FRotator(0.0, RawNewRotation, 0.0);

	if (IsPlayer){ SetRelativeRotation(FRotator(0.0, DesiredRotation.Yaw - 180, 0.0));	}

	else{ 
		
		//UE_LOG(LogTemp, Warning, TEXT("Desired yaw: %f Current yaw: %f"), DesiredRotation.Yaw, CurrentRotation.Yaw);

		SetRelativeRotation(FRotator(0.0, DesiredRotation.Yaw + yawCompensation, 0.0));  
	
	}

	/*
	if (CurrentRotation.Yaw != DesiredRotation.Yaw)
	{
			
		//SetRelativeRotation(NewRotation);

	}
	*/
	//SetRelativeRotation(FRotator(0.0, DesiredRotation.Yaw - 180, 0.0));

}
