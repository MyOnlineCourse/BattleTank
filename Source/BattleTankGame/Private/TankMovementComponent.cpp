// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {

	if(LeftTrackToSet && RightTrackToSet){
	
		LeftTrack = LeftTrackToSet;
		RightTrack = RightTrackToSet;
	
	}

	else { return; }

}

void UTankMovementComponent::IntendMoveForward(float Throw)
{

	if (LeftTrack && RightTrack) {

		UE_LOG(LogTemp, Warning, TEXT("INTEND MOVE FORWARD Current Throttle: %f"), Throw);

		LeftTrack->SetThrottle(Throw);
		RightTrack->SetThrottle(Throw);

	}

}
