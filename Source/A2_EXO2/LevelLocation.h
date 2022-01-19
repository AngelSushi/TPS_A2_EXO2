#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "SaveController.h"
#include "LevelLocation.generated.h"

UCLASS()
class A2_EXO2_API ALevelLocation : public AActor
{
	GENERATED_BODY()
	
public:	
	ALevelLocation();

	UPROPERTY(EditAnywhere)
	FString locationName;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* meshComponent;

	UPROPERTY(EditAnywhere)
	UBoxComponent* hitBox;

	UPROPERTY(EditAnywhere)
	ASaveController* save;



protected:
	virtual void BeginPlay() override;

public: 

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
