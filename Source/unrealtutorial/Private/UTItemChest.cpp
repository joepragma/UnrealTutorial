// Fill out your copyright notice in the Description page of Project Settings.


#include "UTItemChest.h"

// Sets default values
AUTItemChest::AUTItemChest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	RootComponent = BaseMesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>("LidMesh");
	LidMesh->SetupAttachment(BaseMesh);
	LidOpenPitch = 110;
}

// Called when the game starts or when spawned
void AUTItemChest::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AUTItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AUTItemChest::Interact_Implementation(APawn* InstigatorPawn)
{
	LidMesh->SetRelativeRotation(FRotator(LidOpenPitch, 0, 0));
}
