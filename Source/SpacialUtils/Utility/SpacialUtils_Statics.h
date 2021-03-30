// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


// Unreal
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

// UHT
#include "SpacialUtils_Statics.generated.h"



UENUM(BlueprintType)
enum class EDirectionViewMode : uint8
{
	Vector,
	Plane,
	Both
};

UENUM(BlueprintType)
enum class EViewMode : uint8
{
	Location,
	Forward,
	Right,
	Up,
	Orientation,
	Scale,
	Transform
};



//class ASpacialViewer;
//class ASpacialInstancedViewer;



/**
 * 
 */
UCLASS()
class SPACIALUTILS_API USpacialUtils_Statics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


public:

	//UFUNCTION(BlueprintCallable, Category = "Spacial Utils", meta = (DisplayName = "Warm-up Pool"))
	//static void WarmupPool(int32 _preloadCount);

	//static ASpacialViewer* Request_InstanceViewer();	

	// NOT IMPLEMENTED
	//static ASpacialViewer* Request_Viewer();

	// NOT IMPLEMENTED
	//static void Release_Viewer(ASpacialViewer* _viewer);

	// NOT IMPLEMENTED
	//static void Release_InstanceViewer();

	//UFUNCTION(BlueprintCallable, Category = "Spacial Utils", meta = (DisplayName = "Track: Actor Location"))
	//static void Track_ActorLocation(AActor* _actorToTrack);

	//UFUNCTION(BlueprintCallable, Category = "Spacial Utils", meta = (DisplayName = "Track: Actor Direction"))



	//UFUNCTION(BlueprintCallable, Category = "Spacial Utils", Meta = (DisplayName = "Set Viewer Type"))
	//static void Set_ViewerType(UClass* _viewerType);

	//static void Track_Location(FVector& _vector);


	//static void View_Vector(FVector _origin, FVector _vector);

	//static void View_Component(FVector _origin, FVector _vector, EAxis _component);


protected:

	//static UClass* viewerType;

	//static TArray<ASpacialViewer*> viewerPool_Active;
	//static TArray<ASpacialViewer*> viewerPool_Available;

	//static TArray<ASpacialInstancedViewer*> instancedViewerPool_Active;
	//static TArray<ASpacialInstancedViewer*> instancedViewerPool_Available;
};
