// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelZone.h"
#include "PanelWidget.h"
#include "Widget.h"
#include "Blueprint/UserWidget.h"
#include "ZonesGlobalMap.generated.h"


/**
 * 
 */
UCLASS()
class GLOBALMAP_API UZonesGlobalMap : public UUserWidget
{
	GENERATED_BODY()
public:

	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	FName eventName = FName(TEXT("Haha"));
	UFUNCTION(BlueprintCallable)
		void initializeWidget();
	UFUNCTION(BlueprintCallable)
		ULevelZone* getLevelZone();
private:
	ULevelZone * levelZone;
};
