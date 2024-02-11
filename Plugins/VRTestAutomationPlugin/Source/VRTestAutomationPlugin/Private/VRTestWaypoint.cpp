// Fill out your copyright notice in the Description page of Project Settings.


#include "VRTestWaypoint.h"

// Sets default values
AVRTestWaypoint::AVRTestWaypoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AVRTestWaypoint::ApplyWaypointToVRPawn(APawn* VRPawn)
{
	if (VRPawn)
	{
		// put pawn in waypoint position
		VRPawn->TeleportTo(HeadsetPosition, FRotator(0, 0, 0));
	}
}

// Called when the game starts or when spawned
void AVRTestWaypoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVRTestWaypoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

