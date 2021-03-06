// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Unreal
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

// UHT
#include "SpacialView_Component.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACIALUTILS_API USpacialView_Component : public UActorComponent
{
	GENERATED_BODY()

public:

	// Sets default values for this component's properties
	USpacialView_Component();


	//Show Location



	// UActorComponent

protected:

	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
