// Fill out your copyright notice in the Description page of Project Settings.


#include "UTAttributeComponent.h"

// Sets default values
UUTAttributeComponent::UUTAttributeComponent()
{
	Health = 100;
}

bool UUTAttributeComponent::IsAlive()
{
	return Health > 0.0f;
}

bool UUTAttributeComponent::ApplyHealthChange(float Delta)
{
	Health += Delta;
	OnHealthChanged.Broadcast(/*Instigator*/ nullptr, this, Health, Delta);
	return true;
}
