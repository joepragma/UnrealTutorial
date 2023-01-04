// Fill out your copyright notice in the Description page of Project Settings.


#include "UTInteractionComponent.h"

#include "DrawDebugHelpers.h"
#include "UTGameplayInterface.h"

// Sets default values for this component's properties
UUTInteractionComponent::UUTInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UUTInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

// Called every frame
void UUTInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UUTInteractionComponent::PrimaryInteract()
{
	AActor* Owner = GetOwner();
	FVector EyeLocation;
	FRotator EyeRotation;
	Owner->GetActorEyesViewPoint(EyeLocation, EyeRotation);
	
	const FVector StartLocation = EyeLocation;
	const FVector EndLocation = EyeLocation + EyeRotation.Vector() * 1000;

	FCollisionObjectQueryParams CollisionObjectQueryParams;
	CollisionObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(Hit, StartLocation, EndLocation, CollisionObjectQueryParams);

	AActor* HitActor = Hit.GetActor();
	if (HitActor != nullptr && HitActor->Implements<UUTGameplayInterface>())
	{
		IUTGameplayInterface::Execute_Interact(HitActor, Cast<APawn>(Owner));
	}

	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, 0.0f, 2.0f);
}
