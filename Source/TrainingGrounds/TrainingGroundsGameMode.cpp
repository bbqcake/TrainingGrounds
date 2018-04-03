// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TrainingGroundsGameMode.h"
#include "TrainingGroundsHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATrainingGroundsGameMode::ATrainingGroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Character/Behavior/Character"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATrainingGroundsHUD::StaticClass();
}
