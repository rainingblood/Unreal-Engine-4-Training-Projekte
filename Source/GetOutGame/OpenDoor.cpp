// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Engine.h" // Erweiter Corminimal


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay(); // Spielbeginn
}

//void UOpenDoor::OpenDoor()
//{
//	//Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));  // 
//}

//void UOpenDoor::CloseDoor()
//{
//	Owner->SetActorRotation(FRotator(0.f, 179.f, 0.f));
//}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume 
	// Hier wird der Trigger Volume angesprochen das der die Tür 
	// öffen soll wenn ein Bestimmt es gewicht auch ihm lasstet
	if (GetTotalMassOfActorOnPlate() > TriggerMass)
	{
		OnOpen.Broadcast();
		//LastTimeOpenTime = GetWorld()->GetTimeSeconds(); // Hier Speichert LastTimeOpenTime, den letzten Zeitlichen zustand der Tür, in Sekunden.
	}

	else //(GetWorld()->GetTimeSeconds() - LastTimeOpenTime > DoorCloseDelay) // GetWorld()->GetTimeSeconds() <- Aktuelle Zeit  - letzten Zeitlichen zustand der Tür >  5sek (DoorCloseDelay) <- Selbst erstellte float variable
	{
		OnClose.Broadcast();
	}
}

float UOpenDoor::GetTotalMassOfActorOnPlate() // Berechent den Gesamt wert den auf den TriggerVolume ist
{
	float TotalMass = 0.f;

	// Finde all the overlapping actors
	TArray<AActor*> OverlappingActors;
	PressurPlate->GetOverlappingActors(OverlappingActors);

	// Iterate through them adding their masses
	for (const auto& Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass(); // TotalMass, Speichert den gesamt Wert, Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass(), gipt uns die Wertigkeit der einzelenen Objekte.
	}

	return TotalMass;
}
