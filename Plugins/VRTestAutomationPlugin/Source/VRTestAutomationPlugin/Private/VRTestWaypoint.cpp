// Fill out your copyright notice in the Description page of Project Settings.


#include "VRTestWaypoint.h"
#include "MotionControllerComponent.h"

// Sets default values
AVRTestWaypoint::AVRTestWaypoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a root component for in world placement
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	// Create headset as component of root
	Headset = CreateDefaultSubobject<USceneComponent>(TEXT("Headset"));
	Headset->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);

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

	// Attach visual meshes to components
	HeadsetMesh->SetupAttachment(Headset); 
	LControllerMesh->SetupAttachment(LeftControllerComponent);
	RControllerMesh->SetupAttachment(RightControllerComponent);
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
		VRPawn->TeleportTo(Headset->GetComponentLocation(), Headset->GetComponentRotation());
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

