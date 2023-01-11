// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UTGameplayInterface.h"
#include "GameFramework/Actor.h"
#include "UTItemChest.generated.h"

UCLASS()
class UNREALTUTORIAL_API AUTItemChest : public AActor, public IUTGameplayInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AUTItemChest();

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* LidMesh;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float LidOpenPitch;
	
	virtual void Interact_Implementation(APawn* InstigatorPawn) override;
};
