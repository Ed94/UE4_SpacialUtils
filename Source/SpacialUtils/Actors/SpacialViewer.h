// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Unreal
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Project
#include "SpacialUtils_Statics.h"

// UHT
#include "SpacialViewer.generated.h"



class UStaticMeshComponent;
class USplineMeshComponent;



UCLASS()
class SPACIALUTILS_API ASpacialViewer : public AActor
{
	GENERATED_BODY()
	
public:	

	static constexpr float Default_SyncInterval = 1.0f / 60.0f;

	// Sets default values for this actor's properties
	ASpacialViewer();

	
	// Visibility Access

	UFUNCTION(BlueprintCallable, Meta = (DisplayName = "Show Location"))
	void ShowLocation();

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
	void ShowView(EViewMode _viewMode = EViewMode::Transform, EDirectionViewMode _directionViewMode = EDirectionViewMode::Vector, bool _useGnomon = true, bool _showScale = true);

	// Hide

	UFUNCTION(BlueprintCallable, Meta = (DisplayName = "Hide Position"))
	void HideLocation();

	UFUNCTION(BlueprintCallable, Meta = (DisplayName = "Hide Forward"))
	void HideForward();

	UFUNCTION(BlueprintCallable, Meta = (DisplayName = "Hide Right"))
	void HideRight();

	UFUNCTION(BlueprintCallable, Meta = (DisplayName = "Hide Up"))
	void HideUp();

	UFUNCTION(BlueprintCallable, Meta = (DisplayName = "Hide Orientation"))
	void HideOrientation();

	UFUNCTION(BlueprintCallable, Meta = (DisplayName = "Hide Transform"))
	void HideTransform();

	void HideView();


	UPROPERTY(EditAnywhere)
	float SyncInterval = Default_SyncInterval;

	// Viewables

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Root;   // Done to remove the scene component icon.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Location", Meta = (DisplayName = "Location Sphere"))
	UStaticMeshComponent* LocationSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Forward", Meta = (DisplayName = "Forward Arrow")) USplineMeshComponent* Forward_Arrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Forward", Meta = (DisplayName = "Forward Face"))  UStaticMeshComponent* Forward_Face;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Right", Meta = (DisplayName = "Right Arrow")) USplineMeshComponent* Right_Arrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Right", Meta = (DisplayName = "Right Face"))  UStaticMeshComponent* Right_Face;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Up", Meta = (DisplayName = "Up Arrow")) USplineMeshComponent* Up_Arrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Up", Meta = (DisplayName = "Up Face"))  UStaticMeshComponent* Up_Face;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scale", Meta = (DisplayName = "Orientation Gnomon"))
	UStaticMeshComponent* OrientationGnomon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scale", Meta = (DisplayName = "Scale Cube"))
	UStaticMeshComponent* ScaleCube;


protected:

	virtual void SetupComponents();



	// Actor

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
