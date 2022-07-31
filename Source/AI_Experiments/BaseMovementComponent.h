// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kinematic.h"
#include "BaseMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AI_EXPERIMENTS_API UBaseMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBaseMovementComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetTargetPosition(FVector NewPosition) { Target.Position = NewPosition; }
	UFUNCTION(BlueprintCallable)
	void SetMaxSpeed(float NewSpeed) { MaxSpeed = NewSpeed; }
	UFUNCTION(BlueprintCallable)
	void SetMaxAcceleration(float NewAcceleration) { MaxAcceleration = NewAcceleration; }

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	FKinematic Character;
	FKinematic Target;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxSpeed = 300.f;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxAcceleration = 25.f;

	virtual SteeringOutput GetSteering();

};
