// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpacialUtilsGameMode.h"
#include "SpacialUtilsHUD.h"
#include "SpacialUtilsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASpacialUtilsGameMode::ASpacialUtilsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/_Imported/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASpacialUtilsHUD::StaticClass();
}
