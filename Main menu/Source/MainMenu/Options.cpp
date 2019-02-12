// Fill out your copyright notice in the Description page of Project Settings.

#include "Options.h"

void UOptions::openWidget() {
	SetVisibility(ESlateVisibility::Visible);
}

bool UOptions::initialize(UVerticalBox* mainVerticalBox, UVerticalBox* additionalVerticalBox, UDataTable* defaultKeys) {
	if (mainVerticalBox == nullptr || additionalVerticalBox == nullptr) return false;
	getSelectorsFromVerticalBox(mainVerticalBox, &mainSelectors);
	getSelectorsFromVerticalBox(additionalVerticalBox, &additionalSelectors);
	isInitializeSelectors = false;
	this->defaultKeys = defaultKeys;
	initializeAllSelectors();
	return true;
}

/**
* ѕолучаем все селекторы из VerticalBox
* @param verticalBox - VerticalBox из которого будут вытаскиватьс€ селекторы
* @param selectorsArray - массив дл€ хранени€ селекторов
*/
void UOptions::getSelectorsFromVerticalBox(UVerticalBox * verticalBox, TArray<UInputKeySelector*>* selectorsArray) {
	int32 numOfChildren = verticalBox->GetChildrenCount();
	for (int i = 0; i < numOfChildren; i++) {
		UPanelWidget* container = Cast<UPanelWidget>(verticalBox->GetChildAt(i));
		if (container == nullptr) continue;
		UInputKeySelector* selector = Cast<UInputKeySelector>(container->GetChildAt(0));
		if (selector == nullptr) continue;
		else selectorsArray->Add(selector);
	}
}

void UOptions::initializeAllSelectors() {
	isInitializeSelectors = true;
	initializeSelectors(mainSelectors, mainKeys);
	initializeSelectors(additionalSelectors, additionalKeys);
	isInitializeSelectors = false;
}

void UOptions::initializeSelectors(TArray<UInputKeySelector*> &selectorsArray, TArray<FKey> keysArray) {
	for (uint8 index = 0; index < selectorsArray.Num(); index++)
		selectorsArray[index]->SetSelectedKey(FInputChord(keysArray[index]));
}

void UOptions::setToDefaultAxisMappings() {
	clearKeysArrays();
	UInputSettings* inputSettings = UInputSettings::GetInputSettings();
	deleteAllAxisKeyMappings(inputSettings);
	TArray<FName> rowNames = defaultKeys->GetRowNames();
	for (uint8 index = 0; index < rowNames.Num(); index++) {
		FKeyTableRow* tableRow = defaultKeys->FindRow<FKeyTableRow>(rowNames[index], FString(TEXT("")));
		FInputAxisKeyMapping keyMapping;
		keyMapping.AxisName = tableRow->axisName;
		keyMapping.Key = tableRow->key;
		keyMapping.Scale = tableRow->scale;
		inputSettings->AddAxisMapping(keyMapping, true);
		if (index < 4)
			mainKeys.Add(tableRow->key);
		else if (index < 8)
			additionalKeys.Add(tableRow->key);
		else if (index < 12)
			cameraKeys.Add(tableRow->key);
	}
	SaveConfig();
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Saved!"));
	initializeAllSelectors();
}

void UOptions::deleteAllAxisKeyMappings(UInputSettings* inputSettings) {
	TArray<FName> axisNames = TArray<FName>();
	TArray<FInputAxisKeyMapping> axisMappings = TArray<FInputAxisKeyMapping>();
	inputSettings->GetAxisNames(axisNames);
	for (uint8 axisIndex = 0; axisIndex < axisNames.Num(); axisIndex++) {
		inputSettings->GetAxisMappingByName(axisNames[axisIndex], axisMappings);
		for (uint8 mappingIndex = 0; mappingIndex < axisMappings.Num(); mappingIndex++) {
			inputSettings->RemoveAxisMapping(axisMappings[mappingIndex]);
		}
	}
}

void UOptions::clearKeysArrays() {
	mainKeys.Empty();
	additionalKeys.Empty();
	cameraKeys.Empty();
}

void UOptions::findKeyForRemap(UInputKeySelector* selector) {
	//¬озможное место ошибки
	FKey keyNone = EKeys::AnyKey;
	FKey selectedKey = selector->SelectedKey.Key;
	if (selectedKey == keyNone) {
		keyForRemap.AxisName = "None";
		keyForRemap.Key = keyNone;
		keyForRemap.Scale = 0.f;
	}
	else {
		UInputSettings* inputSettings = UInputSettings::GetInputSettings();
		TArray<FName> axisNames = TArray<FName>();
		inputSettings->GetAxisNames(axisNames);
		for (FName axisName : axisNames) {
			if (axisName == FName("MoveCameraForward") || axisName == FName("MoveCameraRight"))
				continue;
			TArray<FInputAxisKeyMapping> inputAxisKeyMappings = TArray<FInputAxisKeyMapping>();
			inputSettings->GetAxisMappingByName(axisName, inputAxisKeyMappings);
			for (FInputAxisKeyMapping inputAxisKeyMapping : inputAxisKeyMappings) {
				if (inputAxisKeyMapping.Key == selectedKey) {
					keyForRemap = inputAxisKeyMapping;
					inputSettings->RemoveAxisMapping(keyForRemap, true);
					return;
				}
			}
		}
	}
}