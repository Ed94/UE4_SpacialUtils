// Fill out your copyright notice in the Description page of Project Settings.


// Parent
#include "SpacialViewer.h"

// Unreal
#include "Components/StaticMeshComponent.h"
#include "Components/SplineMeshComponent.h"

// Project
#include "Utility/SpacialUtils_Statics.h"



// Public

// Sets default values
ASpacialViewer::ASpacialViewer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PrimaryActorTick.TickGroup = TG_PostPhysics;

	SetCanBeDamaged(false);

	this->SetActorTickEnabled(false);

	SetupComponents();
}

void ASpacialViewer::ShowLocation()
{
	LocationSphere->SetVisibility(true);
}

void ASpacialViewer::ShowForward(EDirectionViewMode _viewMode)
{
	switch (_viewMode)
	{
		case EDirectionViewMode::Vector:
		{
			Forward_Arrow->SetVisibility(true);	

		} break;

		case EDirectionViewMode::Plane:
		{
			Forward_Face->SetVisibility(true);

		} break;

		case EDirectionViewMode::Both:
		{
			Forward_Arrow->SetVisibility(true);	
			Forward_Face ->SetVisibility(true);

		} break;
	}
}

void ASpacialViewer::ShowRight(EDirectionViewMode _viewMode)
{
	switch (_viewMode)
	{
		case EDirectionViewMode::Vector:
		{
			Right_Arrow->SetVisibility(true);	

		} break;

		case EDirectionViewMode::Plane:
		{
			Right_Face->SetVisibility(true);

		} break;

		case EDirectionViewMode::Both:
		{
			Right_Arrow->SetVisibility(true);	
			Right_Face ->SetVisibility(true);

		} break;
	}
}

void ASpacialViewer::ShowUp(EDirectionViewMode _viewMode)
{
	switch (_viewMode)
	{
		case EDirectionViewMode::Vector:
		{
			Up_Arrow->SetVisibility(true);	

		} break;

		case EDirectionViewMode::Plane:
		{
			Up_Face->SetVisibility(true);

		} break;

		case EDirectionViewMode::Both:
		{
			Up_Arrow->SetVisibility(true);	
			Up_Face ->SetVisibility(true);

		} break;
	}
}

void ASpacialViewer::ShowOrientation(bool _useGnomon)
{
	if (_useGnomon)
	{
		OrientationGnomon->SetVisibility(true);
	}
	else
	{
		Forward_Arrow->SetVisibility(true);
		Forward_Face ->SetVisibility(true);
		Right_Arrow  ->SetVisibility(true);
		Right_Face   ->SetVisibility(true);
		Up_Arrow     ->SetVisibility(true);
		Up_Face      ->SetVisibility(true);
	}
}

void ASpacialViewer::ShowScale()
{
	ScaleCube->SetVisibility(true);
}

void ASpacialViewer::ShowTransform(bool _useGnomon, bool _showScale)
{
	LocationSphere->SetVisibility(true);

	ShowOrientation(_useGnomon);

	ScaleCube->SetVisibility(_showScale);
}

void ASpacialViewer::ShowView(EViewMode _viewMode, EDirectionViewMode _directionViewMode, bool _useGnomon, bool _useScale)
{
	switch (_viewMode)
	{
		case EViewMode::Location:
		{
			LocationSphere->SetVisibility(true);

		} break;

		case EViewMode::Forward:
		{
			ShowForward(_directionViewMode);

		} break;

		case EViewMode::Right:
		{
			ShowRight(_directionViewMode);

		} break;

		case EViewMode::Up:
		{
			ShowUp(_directionViewMode);

		} break;

		case EViewMode::Orientation:
		{
			ShowOrientation(_useGnomon);
			
		} break;

		case EViewMode::Scale:
		{
			ScaleCube->SetVisibility(true);

		} break;

		case EViewMode::Transform:
		{
			ShowTransform(_useGnomon, _useScale);

		} break;
	}
}

void ASpacialViewer::HideLocation()
{
	LocationSphere->SetVisibility(false);
}

void ASpacialViewer::HideForward()
{
	Forward_Arrow->SetVisibility(false);
	Forward_Face ->SetVisibility(false);
}

void ASpacialViewer::HideRight()
{
	Right_Arrow->SetVisibility(false);
	Right_Face ->SetVisibility(false);
}

void ASpacialViewer::HideUp()
{
	Up_Arrow->SetVisibility(false);
	Up_Face ->SetVisibility(false);
}

void ASpacialViewer::HideOrientation()
{
	OrientationGnomon->SetVisibility(false);
}

void ASpacialViewer::HideTransform()
{
	LocationSphere   ->SetVisibility(false);
	OrientationGnomon->SetVisibility(false);
	ScaleCube        ->SetVisibility(false);
}

void ASpacialViewer::HideView()
{
	LocationSphere   ->SetVisibility(false);
	Forward_Arrow    ->SetVisibility(false);
	Forward_Face     ->SetVisibility(false);
	Right_Arrow      ->SetVisibility(false);
	Right_Face       ->SetVisibility(false);
	Up_Arrow         ->SetVisibility(false);
	Up_Face          ->SetVisibility(false);
	OrientationGnomon->SetVisibility(false);
	ScaleCube        ->SetVisibility(false);
}


// Protected

void ASpacialViewer::SetupComponents()
{
	// Statics

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cube  (TEXT("/Engine/BasicShapes/Cube"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Sphere(TEXT("/Engine/BasicShapes/Sphere"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Arrow (TEXT("/Niagara/DefaultAssets/S_Arrow"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Gnomon(TEXT("/Niagara/DefaultAssets/S_Gnomon"));

	static ConstructorHelpers::FObjectFinder<UMaterial> Mat_Gnomon(TEXT("/Niagara/DefaultAssets/M_Gnomon"));

	static ConstructorHelpers::FObjectFinder<UMaterialInstance> Mat_Red  (TEXT("/Game/Materials/Red_0-5_Alpha"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> Mat_Green(TEXT("/Game/Materials/Green_0-5_Alpha"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> Mat_Blue (TEXT("/Game/Materials/Blue_0-5_Alpha"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> Mat_Black(TEXT("/Game/Materials/Black_0-5_Alpha"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> Mat_White(TEXT("/Game/Materials/White_0-5_Alpha"));


	Root              = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root"));
	LocationSphere    = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Location Sphere"));
	Forward_Arrow     = CreateDefaultSubobject<USplineMeshComponent>(TEXT("Forward Arrow"));
	Forward_Face      = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Forward Face"));
	Right_Arrow       = CreateDefaultSubobject<USplineMeshComponent>(TEXT("Right Arrow"));
	Right_Face        = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right Face"));
	Up_Arrow          = CreateDefaultSubobject<USplineMeshComponent>(TEXT("Up Arrow"));
	Up_Face           = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Up Face"));
	OrientationGnomon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Orientation Gnomon"));
	ScaleCube         = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Scale Cube"));

	Forward_Arrow->SetMobility(EComponentMobility::Movable);
	Right_Arrow  ->SetMobility(EComponentMobility::Movable);
	Up_Arrow     ->SetMobility(EComponentMobility::Movable);

	RootComponent = Root;
	
	LocationSphere   ->SetupAttachment(Root);
	Forward_Arrow    ->SetupAttachment(Root);
	Forward_Face     ->SetupAttachment(Root);
	Right_Arrow      ->SetupAttachment(Root);
	Right_Face       ->SetupAttachment(Root);
	Up_Arrow         ->SetupAttachment(Root);
	Up_Face          ->SetupAttachment(Root);
	OrientationGnomon->SetupAttachment(Root);
	ScaleCube        ->SetupAttachment(Root);

	LocationSphere->SetStaticMesh(Sphere.Object);
	LocationSphere->SetMaterial  (0, Mat_White.Object);

	Forward_Arrow->SetStaticMesh(Arrow.Object);
	Right_Arrow  ->SetStaticMesh(Arrow.Object);
	Up_Arrow     ->SetStaticMesh(Arrow.Object);

	Forward_Arrow->SetMaterial(0, Mat_Red.Object);
	Right_Arrow  ->SetMaterial(0, Mat_Green.Object);
	Up_Arrow     ->SetMaterial(0, Mat_Blue.Object);

	Forward_Face->SetStaticMesh(Cube.Object);
	Right_Face  ->SetStaticMesh(Cube.Object);
	Up_Face     ->SetStaticMesh(Cube.Object);

	Forward_Face->SetMaterial(0, Mat_Red.Object);
	Right_Face  ->SetMaterial(0, Mat_Green.Object);
	Up_Face     ->SetMaterial(0, Mat_Blue.Object);

	OrientationGnomon->SetStaticMesh(Gnomon.Object);
	OrientationGnomon->SetMaterial  (0, Mat_Gnomon.Object);

	ScaleCube->SetStaticMesh(Cube.Object);
	ScaleCube->SetMaterial  (0, Mat_Black.Object);

	LocationSphere->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));

	Forward_Face->SetRelativeScale3D(FVector(0.0f, 1.0f, 1.0f));
	Right_Face  ->SetRelativeScale3D(FVector(1.0f, 0.0f, 1.0f));
	Up_Face     ->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.0f));

	Forward_Arrow->SetStartPosition(FVector  ( 0.0f, 0.0f, 0.0f), false);
	Forward_Arrow->SetEndPosition  (FVector  (50.0f, 0.0f, 0.0f), false);
	Forward_Arrow->SetStartTangent (FVector  (0.0f, 0.0f,  0.0f), false);
	Forward_Arrow->SetEndTangent   (FVector  (0.0f, 0.0f,  0.0f), false);
	Forward_Arrow->SetStartScale   (FVector2D( 3.0f, 3.0f      ), false);
	Forward_Arrow->SetEndScale     (FVector2D( 3.0f, 3.0f      ), true );

	Right_Arrow->SetStartPosition(FVector  (0.0f,  0.0f, 0.0f), false);
	Right_Arrow->SetEndPosition  (FVector  (0.0f, 50.0f, 0.0f), false);
	Right_Arrow->SetStartTangent (FVector  (0.0f, 0.0f,  0.0f), false);
	Right_Arrow->SetEndTangent   (FVector  (0.0f, 0.0f,  0.0f), false);
	Right_Arrow->SetStartScale   (FVector2D(3.0f,  3.0f      ), false);
	Right_Arrow->SetEndScale     (FVector2D(3.0f,  3.0f      ), true );

	Up_Arrow->SetStartPosition(FVector  (0.0f, 0.0f,  0.0f), false);
	Up_Arrow->SetEndPosition  (FVector  (0.0f, 0.0f, 50.0f), false);
	Up_Arrow->SetStartTangent (FVector  (1.0f, 0.0f,  0.0f), false);
	Up_Arrow->SetEndTangent   (FVector  (1.0f, 0.0f,  0.0f), false);
	Up_Arrow->SetStartScale   (FVector2D(3.0f, 3.0f       ), false);
	Up_Arrow->SetEndScale     (FVector2D(3.0f, 3.0f       ), true );

	OrientationGnomon->SetRelativeScale3D(FVector(4.0f, 4.0f, 4.0f));

	LocationSphere   ->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Forward_Arrow    ->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Right_Arrow      ->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Up_Arrow         ->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Forward_Face     ->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Right_Face       ->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Up_Face          ->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	OrientationGnomon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ScaleCube        ->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	HideView();
}



// Actor

// Protected

// Called when the game starts or when spawned
void ASpacialViewer::BeginPlay()
{
	Super::BeginPlay();

	SetActorTickInterval(SyncInterval);
}

// Public

// Called every frame
void ASpacialViewer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

