// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractInterface.h"
#include "CanForceGrab.generated.h"

UCLASS()
class DEMO_ROOM_API ACanForceGrab : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACanForceGrab();

	// Functions we inherited from the interface (that we'll customize in CanForceGrab.cpp)

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void OnInteract();
	virtual void OnInteract_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void StartFocus();
	virtual void StartFocus_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void EndFocus();
	virtual void EndFocus_Implementation();

	// Functions that will handle the stages of force grabbing

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void Grab(FVector Location);

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void Push(FVector Direction);

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void Hold();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
