// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankBarrel.h"
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

void UTankAimingComponent::AimAt(FVector TargetLocation, float LaunchSpeed)
{

	FString OurTankName = GetOwner()->GetName();
	
	if (TankBarrel)
	{

		FVector BarrelLocation = TankBarrel->GetComponentLocation();	

		FVector OutLaunchVelocity;
		FVector StartLocation = TankBarrel->GetSocketLocation(FName("Projectile"));

		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();

		FCollisionResponseParams ResponseParams;

		TArray <AActor *> ActorsToIgnore;

		if (UGameplayStatics::SuggestProjectileVelocity(

			this,
			OutLaunchVelocity,
			StartLocation,
			TargetLocation,
			LaunchSpeed,
			false,
			0.0,
			0.0,
			ESuggestProjVelocityTraceOption::DoNotTrace/*,
			ResponseParams,
			ActorsToIgnore,
			true
			*/
			))

		{

			AimDirection = OutLaunchVelocity.GetSafeNormal();
			auto TankName = GetOwner()->GetName();
			UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *TankName, *AimDirection.ToString());
			
			MoveBarrel(TargetLocation);

		}

		else {

			UE_LOG(LogTemp, Warning, TEXT("No aim solve found"));

		}

	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("A barrel is missing"));

	}

}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{

	/*Rotate hatch for horizontal aiming, rotate barrel for vertical aiming*/

	auto BarrelRotator = TankBarrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	TankBarrel->Elevate(5.0);

}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{

	TankBarrel = BarrelToSet;

}