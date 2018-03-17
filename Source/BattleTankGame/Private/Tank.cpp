// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankTurret.h"
#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

/* Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	
}
*/

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector HitLocation, bool IsPlayer)
{

	TankAimingComponent->AimAt(HitLocation, LaunchSpeed, IsPlayer);

}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{

	TankAimingComponent->SetBarrelReference(BarrelToSet);

	Barrel = BarrelToSet;

}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{

	TankAimingComponent->SetTurretReference(TurretToSet);

}

void ATank::Fire()
{

	UE_LOG(LogTemp, Warning, TEXT("BOOM!"));

	if (!Barrel) { return; }

	else{  
	
		//spawn the projectile	
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			
			ProjectileBluePrint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile")),
			FActorSpawnParameters());

		if (Projectile)
		{

			Projectile->LaunchProjectile(LaunchSpeed);

		}

	}

}