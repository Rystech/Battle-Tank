// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

	virtual void Tick( float DeltaTime ) override;

	//Start the tank moving the abrrle to the corssahair
	void AimTowardsCrosshair();

	// Return an Out Param, ture if hit landscape
	bool GetSightRayHitLocation(FVector&  HitLocation) const;

	bool GetLookDirection(FVector2D ScreenPosistion, FVector & LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector & Hitlocation) const;
	
	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.333333;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.f;
};
