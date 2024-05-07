// Fill out your copyright notice in the Description page of Project Settings.


#include "VRTestWaypoint.h"
#include "MotionControllerComponent.h"

// Sets default values
AVRTestWaypoint::AVRTestWaypoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create headset as the root component
	Headset = CreateDefaultSubobject<USceneComponent>(TEXT("Headset"));
	Headset->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	// Create the motion controller components
	LeftControllerComponent = CreateDefaultSubobject<USceneComponent>(TEXT("LeftControllerComponent"));
	RightControllerComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RightControllerComponent"));

	// Attach the motion controller components to the headset component
	LeftControllerComponent->AttachToComponent(Headset, FAttachmentTransformRules::KeepRelativeTransform);
	RightControllerComponent->AttachToComponent(Headset, FAttachmentTransformRules::KeepRelativeTransform);

	// Create Static mesh for headset
	UStaticMeshComponent* HeadsetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HeadsetMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> HeadsetMeshAsset(TEXT("/VRTestAutomationPlugin/Meshes/rift_sf.rift_sf"));
	//static ConstructorHelpers::FObjectFinder<UMaterial> HeadsetMaterialAsset(TEXT("/Engine/BasicShapes/BasicShapeMaterial"));
	if (HeadsetMeshAsset.Succeeded()) { HeadsetMesh->SetStaticMesh(HeadsetMeshAsset.Object); }
	//if (HeadsetMaterialAsset.Succeeded()) { HeadsetMesh->SetMaterial(0, HeadsetMaterialAsset.Object); }

	// Create Static mesh for left controller (using a right controller mesh as it just represent to controller location)
	UStaticMeshComponent* LControllerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LControllerMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> LControllerMeshAsset(TEXT("/VRTestAutomationPlugin/Meshes/Right_Controller.Right_Controller"));
	//static ConstructorHelpers::FObjectFinder<UMaterial> LControllerMaterialAsset(TEXT("/Engine/BasicShapes/BasicShapeMaterial"));
	if (HeadsetMeshAsset.Succeeded()) { LControllerMesh->SetStaticMesh(LControllerMeshAsset.Object); }
	//if (HeadsetMaterialAsset.Succeeded()) { LControllerMesh->SetMaterial(0, LControllerMaterialAsset.Object); }

	// Create Static mesh for right controller
	UStaticMeshComponent* RControllerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RControllerMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> RControllerMeshAsset(TEXT("/VRTestAutomationPlugin/Meshes/Right_Controller.Right_Controller"));
	//static ConstructorHelpers::FObjectFinder<UMaterial> RControllerMaterialAsset(TEXT("/Engine/BasicShapes/BasicShapeMaterial"));
	if (HeadsetMeshAsset.Succeeded()) { RControllerMesh->SetStaticMesh(RControllerMeshAsset.Object); }
	//if (HeadsetMaterialAsset.Succeeded()) { RControllerMesh->SetMaterial(0, RControllerMaterialAsset.Object); }

	// Remove collision on waypoints
	HeadsetMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	LControllerMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RControllerMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Attach visual meshes to components
	HeadsetMesh->SetupAttachment(Headset); 
	LControllerMesh->SetupAttachment(LeftControllerComponent);
	RControllerMesh->SetupAttachment(RightControllerComponent);
}

void AVRTestWaypoint::ApplyWaypointToVRPawn(APawn* VRPawn)
{
	if (VRPawn)
	{
		// put pawn in waypoint position
		VRPawn->TeleportTo(Headset->GetComponentLocation(), Headset->GetComponentRotation());

		//Get motion controller components
		TArray<AActor*> PawnActors;
		VRPawn->GetAttachedActors(PawnActors);
		PawnActors.Add(VRPawn);
		TArray<USceneComponent*> PawnComponents;
		// Checking componets attached to pawn in search of motion controllers
		for (AActor* actor : PawnActors)
		{
			TArray<USceneComponent*> TempComponents;
			actor->GetComponents(TempComponents);
			PawnComponents.Append(TempComponents);
		}

		//Setups where controller components are children of the pawn
		for (USceneComponent* VRPawnComp : PawnComponents) {
			// Attempt to cast component to UMotionControllerComponent
			UMotionControllerComponent* MotionControllerComp = Cast<UMotionControllerComponent>(VRPawnComp);

			if (MotionControllerComp) {
				// Check left controller
				if (MotionControllerComp->MotionSource == FName("Left")) {
					MotionControllerComp->SetWorldLocationAndRotation(LeftControllerComponent->GetComponentLocation(),
						LeftControllerComponent->GetComponentRotation());
				}
				// Check right controller
				else if (MotionControllerComp->MotionSource == FName("Right")) {
					MotionControllerComp->SetWorldLocationAndRotation(RightControllerComponent->GetComponentLocation(),
						RightControllerComponent->GetComponentRotation());
				}
				else { //default
					UE_LOG(LogTemp, Warning, TEXT("Controller motion source finding fail - Default to Right"));
					MotionControllerComp->SetWorldLocationAndRotation(RightControllerComponent->GetComponentLocation(),
						RightControllerComponent->GetComponentRotation());
				}
			}
		}
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

