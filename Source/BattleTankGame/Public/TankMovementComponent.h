// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKGAME_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;

public:
	
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendTurnRight(float Throw);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);
	
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	
};
