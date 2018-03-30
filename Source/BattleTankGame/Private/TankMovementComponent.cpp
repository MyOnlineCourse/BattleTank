// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
	
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{

	if (LeftTrack && RightTrack) {

		UE_LOG(LogTemp, Warning, TEXT("INTEND MOVE FORWARD Current Throttle: %f"), Throw);

		LeftTrack->SetThrottle(Throw);
		RightTrack->SetThrottle(Throw);

	}

}

void UTankMovementComponent::IntendTurnRight(float Throw)
{

	if (LeftTrack && RightTrack) {

		UE_LOG(LogTemp, Warning, TEXT("INTEND TURN RIGHT Current Throttle: %f"), Throw);

		LeftTrack->SetThrottle(Throw);
		RightTrack->SetThrottle(-Throw);

	}

}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) 
{

	FVector AIForwardIntention = MoveVelocity.GetSafeNormal();
	FVector TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();

	IntendMoveForward(FVector::DotProduct(AIForwardIntention, TankForward));
	IntendTurnRight(FVector::CrossProduct(AIForwardIntention, TankForward).Z);

	//UE_LOG(LogTemp, Warning, TEXT("NAME: %s VELOCITY: %s"), *GetOwner()->GetName(), *MoveVelocity.GetSafeNormal().ToString());

}