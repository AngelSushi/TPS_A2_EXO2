#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SData.generated.h"

UCLASS()
class A2_EXO2_API USData : public USaveGame
{
	GENERATED_BODY()

	
public:

	USData();

	UPROPERTY(EditAnywhere)
	FTransform playerTransform;


	
};
