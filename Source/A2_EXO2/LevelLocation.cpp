#include "LevelLocation.h"
#include "Kismet/GameplayStatics.h"
#include "CustomGameInstance.h"

ALevelLocation::ALevelLocation() {
	PrimaryActorTick.bCanEverTick = false;
	locationName = "Village";

	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = meshComponent;

	hitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	hitBox->AttachTo(RootComponent);

	hitBox->OnComponentBeginOverlap.AddDynamic(this, &ALevelLocation::OnOverlapBegin);
}

void ALevelLocation::BeginPlay() {
	Super::BeginPlay();
}

void ALevelLocation::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	UCustomGameInstance* gameInstance = Cast<UCustomGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	if (!gameInstance || !save)
		return;

	gameInstance->currentLocationName = locationName;
	save->SaveDatas(locationName, gameInstance->currentSlotName);
}


