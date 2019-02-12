// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomButton.h"

UCustomButton::UCustomButton()
{
	OnClicked.AddDynamic(this, &UCustomButton::OnClick);
}

void UCustomButton::OnClick()
{
	optionsWidget->openWidget();
}

void UCustomButton::initialize(UOptions* optionsWidget) {
	this->optionsWidget = optionsWidget;
}