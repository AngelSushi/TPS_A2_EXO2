// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CustomGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class A2_EXO2_API UCustomGameInstance : public UGameInstance
{
	GENERATED_BODY()


public:
	UCustomGameInstance();

	UPROPERTY(EditAnywhere)
	FString currentSlotName;

	UPROPERTY(EditAnywhere)
	FString currentLocationName;

};
