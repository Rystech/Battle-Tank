// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		void SetThrottle(float Throttle);
	//Max Driving Fotrce per track in newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 2000000; // Assume 40 ton tank @ 1g accelleration 
	
};
