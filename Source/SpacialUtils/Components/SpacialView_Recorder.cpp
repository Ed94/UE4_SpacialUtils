// Fill out your copyright notice in the Description page of Project Settings.

// Parent
#include "Components/SpacialView_Recorder.h"



// Public

// Sets default values for this component's properties
USpacialView_Recorder::USpacialView_Recorder()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}



// UActorComponent

// Protected

// Called when the game starts
void USpacialView_Recorder::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Public

// Called every frame
void USpacialView_Recorder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

