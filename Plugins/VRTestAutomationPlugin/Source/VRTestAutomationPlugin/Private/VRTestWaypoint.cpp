// Fill out your copyright notice in the Description page of Project Settings.


#include "VRTestWaypoint.h"
#include "MotionControllerComponent.h"

// Sets default values
AVRTestWaypoint::AVRTestWaypoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create headset as root component
	Headset = CreateDefaultSubobject<USceneComponent>(TEXT("Headset"));
	RootComponent = Headset;

	// Create the motion controller components
	LeftControllerComponent = CreateDefaultSubobject<USceneComponent>(TEXT("LeftControllerComponent"));
	RightControllerComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RightControllerComponent"));

	// Attach the motion controller component to the root component or any other component
	LeftControllerComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	RightControllerComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void AVRTestWaypoint::ApplyWaypointToVRPawn(APawn* VRPawn)
{
	if (VRPawn)
	{
		/*UMotionControllerComponent* LeftController = VRPawn->GetComponentByClass<UMotionControllerComponent>();
		UMotionControllerComponent* RightController = ;*/
		//VRPawn->GetComponents();
		//UE_LOG(LogTemp, Warning, TEXT("Your message goes here"));

		// put pawn in waypoint position
		VRPawn->TeleportTo(Headset->GetComponentLocation(), FRotator(0, 0, 0));
		//VRPawn->GetComponentByClass ->TeleportTo(HeadsetPosition, FRotator(0, 0, 0));
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

