// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelZone.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>

void ULevelZone::initializeWidget(UTextBlock* title)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Widget was initialized and opened!"));
	this->title = title;
}
void ULevelZone::openWidget(FName eventName) {
	SetVisibility(ESlateVisibility::Visible);
	//dataTable->FindRow<FName>(eventName, "", true);
}
