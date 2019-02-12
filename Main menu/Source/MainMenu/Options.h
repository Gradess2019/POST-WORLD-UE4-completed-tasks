// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EngineGlobals.h"
#include "Runtime/UMG/Public/Components/VerticalBox.h"
#include "Runtime/UMG/Public/Components/InputKeySelector.h"
#include "Runtime/UMG/Public/Components/PanelWidget.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Runtime/Engine/Classes/GameFramework/SaveGame.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/InputSettings.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "SaveGame_Keys.h"
#include "Blueprint/UserWidget.h"
#include "Options.generated.h"

//#include "Runtime/Slate/Public/Framework/Commands/InputChord.h"
/**
 * 
 */
UCLASS(Config = Input)
class MAINMENU_API UOptions : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(Config, BlueprintReadWrite)
	float ExampleVariable;

	UPROPERTY(Config, BlueprintReadWrite)
	TArray<FKey> mainKeys;

	UPROPERTY(Config, BlueprintReadWrite)
	TArray<FKey> additionalKeys;

	UPROPERTY(Config, BlueprintReadWrite)
	TArray<FKey> cameraKeys;

	UPROPERTY(BlueprintReadOnly)
	TArray<UInputKeySelector*> mainSelectors;

	UPROPERTY(BlueprintReadOnly)
	TArray<UInputKeySelector*> additionalSelectors;
	

	UFUNCTION(BlueprintCallable)
	bool initialize(UVerticalBox* firstVerticalBox, UVerticalBox* secondVeritcalBox, UDataTable* defaultKeys);

	UFUNCTION(BlueprintCallable)
	void setToDefaultAxisMappings();

	UFUNCTION(BlueprintCallable)
	void findKeyForRemap(UInputKeySelector* selector);

	void openWidget();
	
	
private:
	USaveGame_Keys* saveGame;
	UDataTable* defaultKeys;
	FInputAxisKeyMapping keyForRemap;
	bool isInitializeSelectors;

	void getSelectorsFromVerticalBox(UVerticalBox * firstVerticalBox, TArray<UInputKeySelector*>* selectorsArray);
	void deleteAllAxisKeyMappings(UInputSettings* inputSettings);
	void initializeAllSelectors();
	void initializeSelectors(TArray<UInputKeySelector*> &selectorsArray, TArray<FKey> keysArray);
	void clearKeysArrays();
};


USTRUCT(BlueprintType)
struct FKeyTableRow : public FTableRowBase {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FName axisName;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FKey key;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float scale;

	FKeyTableRow()
	{
		axisName = "None";
		key = EKeys::AnyKey;
		scale = 0.f;
	}
};
