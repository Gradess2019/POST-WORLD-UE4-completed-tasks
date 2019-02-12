// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TextBlock.h"
#include "Engine/DataTable.h"
#include "Blueprint/UserWidget.h"
#include "LevelZone.generated.h"



/**
 * 
 */
UCLASS()
class GLOBALMAP_API ULevelZone : public UUserWidget
{
	GENERATED_BODY()
	
public:	
	UTextBlock * title;
	void openWidget(FName eventName);
	UFUNCTION(BlueprintCallable)
		void initializeWidget(UTextBlock* title);
	UPROPERTY(EditDefaultsOnly)
		UDataTable* dataTable;
	
};

UENUM(BlueprintType)
enum class ELevelType : uint8
{
	Attack,
	Defense,
	Random
};

USTRUCT(BlueprintType)
struct FLevelStruct : public FTableRowBase
{
	GENERATED_BODY()
		
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Struct")
		FText eventTitle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Struct")
		int32 eventDificulty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Struct")
		ELevelType eventType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Struct")
		FText eventDescription;

};