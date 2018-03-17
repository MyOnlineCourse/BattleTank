// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankBarrel.h"
#include "TankTurret.h"
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

void UTankAimingComponent::AimAt(FVector TargetLocation, float LaunchSpeed, bool IsPlayer)
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
			//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *TankName, *AimDirection.ToString());
			
			if (TankTurret)
			{

				MoveBarrel(TargetLocation, IsPlayer);

			}

			else
			{

				UE_LOG(LogTemp, Warning, TEXT("Problem- no turret found"));

			}

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

void UTankAimingComponent::MoveBarrel(FVector AimDirection, bool IsPlayer)
{

	/*Rotate hatch for horizontal aiming, rotate barrel for vertical aiming*/

	auto BarrelRotator = TankBarrel->GetForwardVector().Rotation();
	auto TurretRotator = TankTurret->GetForwardVector().Rotation();
	TurretRotator = FRotator(BarrelRotator.Pitch, (BarrelRotator.Yaw - 0), BarrelRotator.Roll);
	BarrelRotator = FRotator((BarrelRotator.Pitch * -1), BarrelRotator.Yaw, BarrelRotator.Roll);
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	auto DeltaRotator2 = FRotator(AimAsRotator.Pitch, (AimAsRotator.Yaw - 180), AimAsRotator.Roll) - TurretRotator;

	FString myName = GetOwner()->GetName();
	
	TankBarrel->Elevate(DeltaRotator.Pitch);
	TankTurret->Rotate(DeltaRotator2.Yaw, TurretRotator, AimAsRotator);

}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{

	TankBarrel = BarrelToSet;

}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{

	TankTurret = TurretToSet;

}