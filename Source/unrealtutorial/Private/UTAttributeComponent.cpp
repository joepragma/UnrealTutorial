// Fill out your copyright notice in the Description page of Project Settings.


#include "UTAttributeComponent.h"

// Sets default values
UUTAttributeComponent::UUTAttributeComponent()
{
	Health = 100;
}

bool UUTAttributeComponent::ApplyHealthChange(float Delta)
{
	Health += Delta;
	return true;
}
