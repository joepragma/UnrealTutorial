// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UTAttributeComponent.h"
#include "UTInteractionComponent.h"
#include "GameFramework/Character.h"
#include "UTCharacter.generated.h"

// Forward declarations
class UCameraComponent;
class USpringArmComponent;
class UUTInteractionComponent;
class UAnimMontage;
class AUTAttributeComponent;

UCLASS()
class UNREALTUTORIAL_API AUTCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AUTCharacter();

protected:
	UPROPERTY(EditAnywhere, Category="Attack")
	TSubclassOf<AActor> MagicAttackClass;

	UPROPERTY(EditAnywhere, Category="Attack")
	UAnimMontage* MagicAttackAnimation;

	FTimerHandle MagicAttackTimerHandler;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere)
	UUTInteractionComponent* InteractionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	AUTAttributeComponent* AttributeComponent;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void MagicAttack();
	void MagicAttackAfterTimer();
	void Interact();
};
