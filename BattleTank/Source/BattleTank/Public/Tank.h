// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;
class UTankTurret;
class UTankMovement;
class AProjectile;
UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable)
		void Fire();



protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovement* TankMovement = nullptr;


private:	
	// Sets default values for this pawn's properties
	ATank();
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 10000;

	UPROPERTY(EditAnywhere, Category = Firing)
		TSubclassOf<AProjectile>  ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;//Local Barrel refrence

	float ReloadTimeInSeconds = 3.0f;

	double LastFireTime = 0;
	
	
};
