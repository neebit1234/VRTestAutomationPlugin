// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "MotionControllerComponent.h"
#include "VRTestWaypoint.generated.h"

//class AVRPawn;

UCLASS()
class VRTESTAUTOMATIONPLUGIN_API AVRTestWaypoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVRTestWaypoint();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VR Waypoint")
	USceneComponent* Headset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VR Waypoint")
	USceneComponent* LeftControllerComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VR Waypoint")
	USceneComponent* RightControllerComponent;

	UFUNCTION(BlueprintCallable, Category = "VR Waypoint")
	void ApplyWaypointToVRPawn(APawn* VRPawn);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
