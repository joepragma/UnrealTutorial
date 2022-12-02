// Fill out your copyright notice in the Description page of Project Settings.


#include "UTMagicProjectile.h"

#include "Particles/ParticleSystemComponent.h"

// Sets default values
AUTMagicProjectile::AUTMagicProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	RootComponent = SphereComponent;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
	ProjectileMovementComponent->InitialSpeed = 1000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bInitialVelocityInLocalSpace = true;

	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>("ParticleSystemComponent");
	ParticleSystemComponent->SetupAttachment(SphereComponent);
}

// Called when the game starts or when spawned
void AUTMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AUTMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
