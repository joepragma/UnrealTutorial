// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UTAttributeComponent.generated.h"

UCLASS()
class UNREALTUTORIAL_API AUTAttributeComponent : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AUTAttributeComponent();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Attributes")
	float Health;

public:
	UFUNCTION(BlueprintCallable, Category="Attributes")
	bool ApplyHealthChange(float Delta);
};
