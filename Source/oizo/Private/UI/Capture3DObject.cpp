// Fill out your copyright notice in the Description page of Project Settings.


#include "Capture3DObject.h"

// Sets default values
ACapture3DObject::ACapture3DObject()
{
 	 // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	MeshToRecord = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshToRecord"));
	MeshToRecord->SetupAttachment(Root);

	Capture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("CaptureBoard"));
	Capture->SetupAttachment(Root);
	Capture->RelativeLocation = FVector(-170,0,65);
	Capture->RelativeRotation = FRotator(0,-20,0);
	auto _myView = FMinimalViewInfo();
	_myView.FOV = 22;
	_myView.ProjectionMode = ECameraProjectionMode::Perspective;
	Capture->SetCameraView(_myView);

}

 //Called when the game starts or when spawned
void ACapture3DObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACapture3DObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

