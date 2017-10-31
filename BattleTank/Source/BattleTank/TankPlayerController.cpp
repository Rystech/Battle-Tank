// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController.h"
#include "BattleTank.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto CurrentPawn = GetPawn();
	if (!CurrentPawn) { UE_LOG(LogTemp, Warning, TEXT("Player Pawn is not found")); }
	else { UE_LOG(LogTemp, Warning, TEXT("Player Pawn is set to: %s"), *CurrentPawn->GetName()); }
}

void ATankPlayerController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation;//out param
	if (GetSightRayHitLocation(HitLocation)) {// has side effect is going to line trace
		GetControlledTank()->AimAt(HitLocation);
	}
}

//get world location if linetrace through crossahir, true if hitsd landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//find the crosshair pos
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenPosistion(
		ViewportSizeX * CrossHairXLocation,
		ViewportSizeY * CrossHairYLocation
	);
	//"De-Project" the screen pos of the crosshair to a wrold dir
	FVector LookDirection;
	if (GetLookDirection(ScreenPosistion,LookDirection ))
	{
		//line trace along that dir and see what we hit(upto max range)
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenPosistion, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // to be disgarded not used
	return DeprojectScreenPositionToWorld(
		ScreenPosistion.X,
		ScreenPosistion.Y,
		CameraWorldLocation,
		LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult LineTraceHitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection*LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			LineTraceHitResult,
			StartLocation,
			EndLocation,
			ECC_Visibility)) 
	{
				HitLocation = LineTraceHitResult.Location;
				return true;
	}
	else 
	{ 
		HitLocation = FVector(0); 
		return false; 
	}
}
ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}