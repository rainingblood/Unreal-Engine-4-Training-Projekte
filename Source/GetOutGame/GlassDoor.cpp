// Fill out your copyright notice in the Description page of Project Settings.

#include "GlassDoor.h"
#include "Engine.h"

// Sets default values for this component's properties
UGlassDoor::UGlassDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UGlassDoor::OpenDoor()
{
	GlassDoor->SetActorLocation(FVector(0.f, OpenAngle, 0.f));
}

void UGlassDoor::CloseDoor()
{
	GlassDoor->SetActorLocation(FVector(0.f, 0.f, 0.f));
}

// Called when the game starts
void UGlassDoor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	OpenDoor();
}


// Called every frame
void UGlassDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

