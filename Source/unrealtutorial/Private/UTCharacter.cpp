// Fill out your copyright notice in the Description page of Project Settings.


#include "UTCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AUTCharacter::AUTCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("USpringArmComponent");
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->SetupAttachment(RootComponent);
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("UCameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	InteractionComponent = CreateDefaultSubobject<UUTInteractionComponent>("UUTInteractionComponent");

	GetCharacterMovement()->bOrientRotationToMovement = true;

	bUseControllerRotationYaw = false;
}

// Called when the game starts or when spawned
void AUTCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AUTCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AUTCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AUTCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AUTCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AUTCharacter::Jump);
	PlayerInputComponent->BindAction("MagicAttack", IE_Pressed, this, &AUTCharacter::MagicAttack);
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AUTCharacter::Interact);
}

void AUTCharacter::MoveForward(float Value)
{
	FRotator CameraRotator = GetControlRotation();
	CameraRotator.Pitch = 0.0f;
	CameraRotator.Roll = 0.0f;
	
	AddMovementInput(CameraRotator.Vector(), Value);
}

void AUTCharacter::MoveRight(float Value)
{
	FRotator CameraRotator = GetControlRotation();
	CameraRotator.Pitch = 0.0f;
	CameraRotator.Roll = 0.0f;

	const FVector RightVector = FRotationMatrix(CameraRotator).GetScaledAxis(EAxis::Y);
	AddMovementInput(RightVector, Value);
}

void AUTCharacter::MagicAttack()
{
	PlayAnimMontage(MagicAttackAnimation);

	GetWorldTimerManager().SetTimer(MagicAttackTimerHandler, this, &AUTCharacter::MagicAttackAfterTimer, 0.2f);
}

void AUTCharacter::MagicAttackAfterTimer()
{
	const FVector RightHandLocation = GetMesh()->GetSocketLocation("Muzzle_01");
	const FTransform SpawnLocationMatrix = FTransform(GetControlRotation(), RightHandLocation);

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParameters.Instigator = this;
	
	GetWorld()->SpawnActor<AActor>(MagicAttackClass, SpawnLocationMatrix, SpawnParameters);
}

void AUTCharacter::Interact()
{
	InteractionComponent->PrimaryInteract();
}
