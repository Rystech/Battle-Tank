// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "UObject/UObjectGlobals.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
	ProjectileMovement->bAutoActivate = false;

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::LaunchProjectile(float Launchspeed)
{
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Launchspeed);
	ProjectileMovement->Activate();
}

