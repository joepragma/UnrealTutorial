// Fill out your copyright notice in the Description page of Project Settings.


#include "UTTargetDummyActor.h"

// Sets default values
AUTTargetDummyActor::AUTTargetDummyActor()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	RootComponent = StaticMeshComponent;

	AttributeComponent = CreateDefaultSubobject<UUTAttributeComponent>("AttributeComponent");
	AttributeComponent->OnHealthChanged.AddDynamic(this, &AUTTargetDummyActor::OnHealthChange);
}

void AUTTargetDummyActor::OnHealthChange(AActor* InstigatorActor, UUTAttributeComponent* OwningComp, float NewHealth,
                                         float Delta)
{
	if (Delta < 0)
	{
		StaticMeshComponent->SetScalarParameterValueOnMaterials("TimeToHit", GetWorld()->TimeSeconds);
	}
}
