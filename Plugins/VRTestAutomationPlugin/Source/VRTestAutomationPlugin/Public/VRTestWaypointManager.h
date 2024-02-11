// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "VRTestWaypoint.cpp"
#include "VRTestWaypointManager.generated.h"

/**
 * 
 */
//class AVRPawn;
//class AVRWaypoint;

UCLASS()
class VRTESTAUTOMATIONPLUGIN_API UVRTestWaypointManager : public UObject
{
	GENERATED_BODY()

public:
	UVRTestWaypointManager();

	UFUNCTION(BlueprintCallable, Category = "VR Waypoint Manager")
	void MoveToWaypoint(APawn* VRPawn, AVRTestWaypoint* Waypoint);

private:
	//
};
