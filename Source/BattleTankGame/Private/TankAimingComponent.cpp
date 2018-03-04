// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UTankAimingComponent::AimAt(FVector TargetLocation)
{

	FString OurTankName = GetOwner()->GetName();
	
	if (TankBarrel)
	{

		FVector BarrelLocation = TankBarrel->GetComponentLocation();	
		UE_LOG(LogTemp, Warning, TEXT("%s aiming at location: %s from %s"), *OurTankName, *TargetLocation.ToString(), *BarrelLocation.ToString());

	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("A barrel is missing"));

	}

}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{

	TankBarrel = BarrelToSet;

}