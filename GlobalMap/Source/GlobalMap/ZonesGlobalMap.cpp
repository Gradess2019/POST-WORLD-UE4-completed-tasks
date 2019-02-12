// Fill out your copyright notice in the Description page of Project Settings.

#include "ZonesGlobalMap.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>

FReply UZonesGlobalMap::NativeOnMouseButtonDown(const FGeometry & InGeometry, const FPointerEvent & InMouseEvent)
{
	FReply fReply = Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is an on screen message!"));
	
	levelZone->openWidget(eventName);
	return fReply;
}

void UZonesGlobalMap::initializeWidget() {
	UPanelWidget * globalMap = GetParent();
	for (int32 childIndex = 0; childIndex < globalMap->GetChildrenCount(); childIndex++)
	{
		if (Cast<ULevelZone>(globalMap->GetChildAt(childIndex)) != nullptr)
		{
			this->levelZone = Cast<ULevelZone>(globalMap->GetChildAt(childIndex));
			break;
		}
	}
}

ULevelZone* UZonesGlobalMap::getLevelZone() {
	return levelZone;
}

