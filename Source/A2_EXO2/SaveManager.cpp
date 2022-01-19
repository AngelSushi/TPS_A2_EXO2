#include "SaveManager.h"
#include "Kismet/GameplayStatics.h"
#include "LevelLocation.h"
#include "CustomGameInstance.h"


USaveManager::USaveManager() {
	PrimaryComponentTick.bCanEverTick = false;
}


void USaveManager::BeginPlay() {
	Super::BeginPlay();

	USkeletalMeshComponent* meshComponent = Cast<USkeletalMeshComponent>(GetOwner()->GetComponentByClass(USkeletalMeshComponent::StaticClass()));

	meshComponent->OnComponentBeginOverlap.AddDynamic(this, &USaveManager::OnOverlapBegin);
}

void USaveManager::SaveDatas(FString locationName,FString slotName) {
	USData* sData = Cast<USData>(UGameplayStatics::CreateSaveGameObject(USData::StaticClass()));
	USListData* sListData = Cast<USListData>(UGameplayStatics::CreateSaveGameObject(USListData::StaticClass()));
	sData->playerTransform = GetOwner()->GetTransform();

	sListData->locationsName.Add(ConvertSlotToInt(slotName),locationName);


	if (UGameplayStatics::SaveGameToSlot(sData, FString(slotName), 0) && UGameplayStatics::SaveGameToSlot(sListData, FString("slotListData"), 0))
		GEngine->AddOnScreenDebugMessage(-1, 5.f,FColor::Green,TEXT("Game Saved"));
	else
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Error during game save"));
}

USListData* USaveManager::LoadDatas(int data) {
	USListData* sListData = Cast<USListData>(UGameplayStatics::CreateSaveGameObject(USListData::StaticClass()));
	UCustomGameInstance* gameInstance = Cast<UCustomGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	sListData = Cast<USListData>(UGameplayStatics::LoadGameFromSlot("slotListData",0));

	return sListData;
}

 void USaveManager::LoadPlayerDatas() {
	 USData* sData = Cast<USData>(UGameplayStatics::CreateSaveGameObject(USData::StaticClass()));
	 UCustomGameInstance* gameInstance = Cast<UCustomGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	 sData = Cast<USData>(UGameplayStatics::LoadGameFromSlot(gameInstance->currentSlotName,0));

	 GetOwner()->SetActorTransform(sData->playerTransform);
 }

void USaveManager::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	ALevelLocation* levelLocation = Cast<ALevelLocation>(OtherActor);
	UCustomGameInstance* gameInstance = Cast<UCustomGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	if (!levelLocation || !gameInstance)
		return;
	
	gameInstance->currentLocationName = levelLocation->locationName;
	SaveDatas(levelLocation->locationName,gameInstance->currentSlotName);
}

int USaveManager::ConvertSlotToInt(FString slot) {
	if (slot == "Slot_01")
		return 0;
	else if (slot == "Slot_02")
		return 1;
	else if (slot == "Slot_03")
		return 2;

	return 0;
}