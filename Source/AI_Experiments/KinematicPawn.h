// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "KinematicMovementComponent.h"
#include "KinematicPawn.generated.h"

UCLASS()
class AI_EXPERIMENTS_API AKinematicPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AKinematicPawn();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UKinematicMovementComponent> KinematicMovementClass;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* StaticMesh;
	
	class USceneComponent* SceneComponent;

};
