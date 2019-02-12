// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/InputCore/Classes/InputCoreTypes.h"
#include "GameFramework/SaveGame.h"
#include "SaveGame_Keys.generated.h"

/**
 * 
 */
UCLASS()
class MAINMENU_API USaveGame_Keys : public USaveGame
{
	GENERATED_BODY()
	
public:
	TArray<FKey> mainKeys;
	TArray<FKey> additionalKeys;
	TArray<FKey> cameraKeys;
	
	USaveGame_Keys();
	
};
