// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SData.h"
#include "SListData.h"
#include "SaveManager.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class A2_EXO2_API USaveManager : public UActorComponent
{
	GENERATED_BODY()

public:
	USaveManager();


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
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	int ConvertSlotToInt(FString slot);
};
