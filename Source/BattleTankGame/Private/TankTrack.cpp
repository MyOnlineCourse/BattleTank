// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{

	UE_LOG(LogTemp, Warning, TEXT("%s Current Throttle: %f"), *GetName(), Throttle);

	FVector ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	FVector ForceLocation = GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()-> GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}
