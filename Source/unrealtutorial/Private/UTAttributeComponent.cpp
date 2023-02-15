// Fill out your copyright notice in the Description page of Project Settings.


#include "UTAttributeComponent.h"

// Sets default values
AUTAttributeComponent::AUTAttributeComponent()
{
	Health = 100;
}

bool AUTAttributeComponent::ApplyHealthChange(float Delta)
{
	Health += Delta;
	return true;
}
