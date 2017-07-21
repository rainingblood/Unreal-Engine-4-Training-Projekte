// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GETOUTGAME_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Find (assumed) attached physics handle
	void SetupInputComponent();

	// Find (assumed) attached input handle
	void FindePhysicsComponent();

	// Return hit for first physics body in reach
	FHitResult GetFirstPhysicsBodyinReach();

	// Gibt den Start punkt der reach line an
	// Returns current start of reach line
	FVector GetReachLineStart();

	// Returns current end of reach line
	FVector GetReachLineEnd();

	// Ray-cast and grab what's in reach
	void Grab();

	// Called when grab is released
	void Released();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	// Wie weit voran der Spieler, greifen kann in cm
	// How far ahead of the Player can we reach in cm
	float Reach = 100.f;
	
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent *InputComponent = nullptr;
};