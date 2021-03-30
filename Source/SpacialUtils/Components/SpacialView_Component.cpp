// Fill out your copyright notice in the Description page of Project Settings.


// Parent
#include "SpacialView_Component.h"



// Public

// Sets default values for this component's properties
USpacialView_Component::USpacialView_Component()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// UActorComponent

// Protected

// Called when the game starts
void USpacialView_Component::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Public

// Called every frame
void USpacialView_Component::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

