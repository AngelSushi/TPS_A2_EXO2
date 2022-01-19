// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SListData.generated.h"

/**
 * 
 */
UCLASS()
class A2_EXO2_API USListData : public USaveGame
{
	GENERATED_BODY()

public:

	USListData();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<int,FString> locationsName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<int,FString> timesPassed;
	
};
