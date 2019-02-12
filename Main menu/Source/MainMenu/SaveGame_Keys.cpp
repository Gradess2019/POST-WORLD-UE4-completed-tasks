// Fill out your copyright notice in the Description page of Project Settings.

#include "SaveGame_Keys.h"

USaveGame_Keys::USaveGame_Keys()
{
	mainKeys.Add(FKey(TEXT("W")));
	mainKeys.Add(FKey(TEXT("S")));
	mainKeys.Add(FKey(TEXT("D")));
	mainKeys.Add(FKey(TEXT("A")));

	additionalKeys.Add(FKey(TEXT("Up")));
	additionalKeys.Add(FKey(TEXT("Down")));
	additionalKeys.Add(FKey(TEXT("Right")));
	additionalKeys.Add(FKey(TEXT("Left")));

	cameraKeys.Add(FKey(TEXT("W")));
	cameraKeys.Add(FKey(TEXT("S")));
	cameraKeys.Add(FKey(TEXT("D")));
	cameraKeys.Add(FKey(TEXT("A")));
}


