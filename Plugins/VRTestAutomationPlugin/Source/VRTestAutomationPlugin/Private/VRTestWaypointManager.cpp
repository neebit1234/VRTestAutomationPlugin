// Fill out your copyright notice in the Description page of Project Settings.


#include "VRTestWaypointManager.h"
#include "VRTestWaypoint.h"

UVRTestWaypointManager::UVRTestWaypointManager()
{
}

void UVRTestWaypointManager::MoveToWaypoint(APawn* VRPawn, AVRTestWaypoint* Waypoint) {
	Waypoint->ApplyWaypointToVRPawn(VRPawn);
}
