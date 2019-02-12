// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include "Options.h"
#include "Components/Button.h"
#include "CustomButton.generated.h"

/**
 * 
 */

UCLASS()
class MAINMENU_API UCustomButton : public UButton
{
	GENERATED_BODY()
	
public:
	UCustomButton();

	UFUNCTION()
		void OnClick();
	UFUNCTION(BlueprintCallable)
		void initialize(UOptions* optionsWidget);
private:
	UOptions* optionsWidget;
};
