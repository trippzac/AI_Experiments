// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseMovementComponent.h"
#include "BasePawn.generated.h"

UCLASS()
class AI_EXPERIMENTS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UBaseMovementComponent> BaseMovementClass;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* StaticMesh;

	class USceneComponent* SceneComponent;

};
