// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"



void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed=FMath::Clamp<float>(RelativeSpeed, -1, +1);
	//move barrel the right amount this frame
	//given the elevation speed and frame time
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, NewRotation, 0));
}
