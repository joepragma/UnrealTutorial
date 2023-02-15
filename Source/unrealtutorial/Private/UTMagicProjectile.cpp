// Fill out your copyright notice in the Description page of Project Settings.


#include "UTMagicProjectile.h"

#include "UTAttributeComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AUTMagicProjectile::AUTMagicProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->SetCollisionProfileName("ProjectileProfile");
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AUTMagicProjectile::OnActorOverlap);
	RootComponent = SphereComponent;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
	ProjectileMovementComponent->InitialSpeed = 1000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bInitialVelocityInLocalSpace = true;

	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>("ParticleSystemComponent");
	ParticleSystemComponent->SetupAttachment(SphereComponent);
}

void AUTMagicProjectile::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                        const FHitResult& SweepResult)
{
	if (OtherActor != nullptr)
	{
		AUTAttributeComponent* AttributeComponent = Cast<AUTAttributeComponent>(
			OtherActor->GetComponentByClass(AUTAttributeComponent::StaticClass()));

		if (AttributeComponent != nullptr)
		{
			AttributeComponent->ApplyHealthChange(-20.0f);
			Destroy();
		}
	}
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
