// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SData.h"
#include "SListData.h"
#include "SaveController.generated.h"

UCLASS()
class A2_EXO2_API ASaveController : public AActor
{
	GENERATED_BODY()
	
public:	
	ASaveController();

protected:
	virtual void BeginPlay() override;

public:

	UFUNCTION()
	void SaveDatas(FString locationName, FString slotName);

	UFUNCTION(BlueprintCallable)
	USListData* LoadDatas(int data);

	UFUNCTION(BlueprintCallable)
	void LoadPlayerDatas();

	UFUNCTION()
	int ConvertSlotToInt(FString slot);
};

