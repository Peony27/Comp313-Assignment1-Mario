// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingBrick.h"

// Sets default values
AFloatingBrick::AFloatingBrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

}

// Called when the game starts or when spawned
void AFloatingBrick::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingBrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewPosition = GetActorLocation();
	FRotator rotation = GetActorRotation();
	float RunningTime = GetGameTimeSinceCreation();
	float currentHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewPosition.Z += currentHeight * 50.0f;       //Scale current height height by a factor of 50
	float DeltaRotation = DeltaTime * 20.0f;    //Rotate by 20 degrees per second
	rotation.Yaw += DeltaRotation;
	SetActorLocationAndRotation(NewPosition, rotation);

}

