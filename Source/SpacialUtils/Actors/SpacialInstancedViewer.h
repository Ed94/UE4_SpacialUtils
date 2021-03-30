// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Unreal
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Project
#include "SpacialUtils_Statics.h"

// UHT
#include "SpacialInstancedViewer.generated.h"



class UHierarchicalInstancedStaticMeshComponent;



/**
 * Will create any views you would normally get with the regular viewr, however these cannot be 
 * 
 * Not: Not implemented.
 */
UCLASS()
class SPACIALUTILS_API ASpacialInstancedViewer : public AActor
{
	GENERATED_BODY()
	
public:	
	
	// Sets default values for this actor's properties
	ASpacialInstancedViewer();


	/*UFUNCTION(BlueprintCallable, Meta = (DisplayName = "Show Position"))
	void ShowPosition();

	UFUNCTION(BlueprintCallable, Meta = (DisplayName = "Show Forward"))
	void ShowForward(EDirectionViewMode _viewMode = EDirectionViewMode::Vector);

	UFUNCTION(BlueprintCallable, Meta = (DisplayName = "Show Right"))
	void ShowRight(EDirectionViewMode _viewMode = EDirectionViewMode::Vector);

	UFUNCTION(BlueprintCallable, Meta = (DisplayName = "Show Up"))
	void ShowUp(EDirectionViewMode _viewMode = EDirectionViewMode::Vector);

	UFUNCTION(BlueprintCallable, Meta = (DisplayName = "Show Orientation"))
	void ShowOrientation(bool _useGnomon = true);

	UFUNCTION(BlueprintCallable, Meta = (DisplayName = "Show Scale"))
	void ShowScale();

	UFUNCTION(BlueprintCallable, Meta = (DisplayName = "Show Transform"))
	void ShowTransform(bool _useGnomon = false, bool _showScale = false);

	UFUNCTION(BlueprintCallable, Meta = (DisplayName = "Show View"))
	void ShowView(EViewMode _viewMode = EViewMode::Transform, EDirectionViewMode _directionViewMode = EDirectionViewMode::Vector, bool _useGnomon = true, bool _showScale = true);*/


	//UHierarchicalInstancedStaticMeshComponent PositionInstances;

	//UHierarchicalInstancedStaticMeshComponent HISM_ArrowForward;

	//UHierarchicalInstancedStaticMeshComponent HISM_ArrowRight;

	//UHierarchicalInstancedStaticMeshComponent HISM_ArrowUp;


	// AActor

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
