// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UTAttributeComponent.h"
#include "GameFramework/Actor.h"
#include "UTTargetDummyActor.generated.h"

UCLASS()
class UNREALTUTORIAL_API AUTTargetDummyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUTTargetDummyActor();

protected:
	UPROPERTY(VisibleAnywhere)
	UUTAttributeComponent* AttributeComponent;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

	UFUNCTION()
	void OnHealthChange(AActor* InstigatorActor, UUTAttributeComponent* OwningComp, float NewHealth, float Delta);
};
