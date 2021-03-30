// Fill out your copyright notice in the Description page of Project Settings.

// Parent
#include "Actors/SpacialInstancedViewer.h"



// Public

// Sets default values
ASpacialInstancedViewer::ASpacialInstancedViewer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}



// Actor

// Protected

// Called when the game starts or when spawned
void ASpacialInstancedViewer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Public

// Called every frame
void ASpacialInstancedViewer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

