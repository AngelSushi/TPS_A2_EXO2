
#include "SaveController.h"
#include "Kismet/GameplayStatics.h"
#include "LevelLocation.h"
#include "CustomGameInstance.h"

ASaveController::ASaveController(){
 	

}

void ASaveController::BeginPlay() {
	Super::BeginPlay();
}

void ASaveController::SaveDatas(FString locationName, FString slotName) {
	USData* sData = Cast<USData>(UGameplayStatics::CreateSaveGameObject(USData::StaticClass()));
	USListData* sListData = Cast<USListData>(UGameplayStatics::CreateSaveGameObject(USListData::StaticClass()));
	sData->playerTransform = this->GetTransform();

	sListData->locationsName.Add(ConvertSlotToInt(slotName), locationName);


	if (UGameplayStatics::SaveGameToSlot(sData, FString(slotName), 0) && UGameplayStatics::SaveGameToSlot(sListData, FString("slotListData"), 0))
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Game Saved"));
	else
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Error during game save"));
}

USListData* ASaveController::LoadDatas(int data) {
	USListData* sListData = Cast<USListData>(UGameplayStatics::CreateSaveGameObject(USListData::StaticClass()));
	UCustomGameInstance* gameInstance = Cast<UCustomGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	sListData = Cast<USListData>(UGameplayStatics::LoadGameFromSlot("slotListData", 0));

	return sListData;
}

void ASaveController::LoadPlayerDatas() {
	USData* sData = Cast<USData>(UGameplayStatics::CreateSaveGameObject(USData::StaticClass()));
	UCustomGameInstance* gameInstance = Cast<UCustomGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	sData = Cast<USData>(UGameplayStatics::LoadGameFromSlot(gameInstance->currentSlotName, 0));

	this->SetActorTransform(sData->playerTransform);
}

int ASaveController::ConvertSlotToInt(FString slot) {
	if (slot == "Slot_01")
		return 0;
	else if (slot == "Slot_02")
		return 1;
	else if (slot == "Slot_03")
		return 2;

	return 0;
}



