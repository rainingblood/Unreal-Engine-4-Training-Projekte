// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent); // So sagt man dass man Blueprint verwenden will in seinem Projekt

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GETOUTGAME_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	UPROPERTY(BlueprintAssignable)   // erstellen eines Blueprint Event
		FDoorEvent OnOpen;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnClose;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	
	// All Propertys
	//UPROPERTY(Editanywhere)     // Erstellt ein editierbares feld im Editor
		//float OpenAngle = 90.f; 

	UPROPERTY(Editanywhere)
		ATriggerVolume* PressurPlate;

	UPROPERTY(Editanywhere)
		float TriggerMass = 25.f; // KG

	//UPROPERTY(Editanywhere)
	//	float DoorCloseDelay = 5.f;

		//float LastTimeOpenTime;

	// Var
	AActor* Owner = GetOwner(); // Das ist die Tür 

	// Returns total mass in kg
	float GetTotalMassOfActorOnPlate();
};