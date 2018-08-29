// Fill out your copyright notice in the Description page of Project Settings.

#include "PM_GridCell.h"



template<typename T>
static FString EnumToString(const FString& enumName, const T value)
{
	UEnum* pEnum = FindObject<UEnum>(ANY_PACKAGE, *enumName);
	return *(pEnum ? pEnum->GetNameStringByIndex(static_cast<uint8>(value)) : "null");
}


// Sets default values
APM_GridCell::APM_GridCell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("ROOT"));
	SetRootComponent(boxCollision);

	bonusMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BonusMesh"));
	bonusMesh->SetupAttachment(RootComponent);

	SetInitialCellValues();
}

// Called when the game starts or when spawned
void APM_GridCell::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APM_GridCell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int APM_GridCell::GetScorePoints()
{
	return scorePoints;
}

ECellPurpose APM_GridCell::GetCellPurpose()
{
	return cellPurpose;
}

bool APM_GridCell::CheckIsPicked()
{
	return isPicked;
}

bool APM_GridCell::CheckIsOcupied()
{
	return isOccupied;
}

void APM_GridCell::Pick()
{
	if (isPicked) { return; }
	
	isPicked = true;
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}


void APM_GridCell::SetInitialCellValues()
{
	FString cellType = EnumToString<ECellPurpose>("ECellPurpose", cellPurpose);
	//UEnum::GetValueAsString(TEXT("Source/PackManGame/Grid/PM_GridCell.h"), cellPurpose);

	//FCellInfo* Row = InfoDataTable->FindRow<FCellInfo>(TEXT("P_Regular"), TEXT("Row missing"));
	//
	//	if (Row)
	//	{
	//		scorePoints = Row->scorePoints;
	//		GLog->Log(scorePoints + " ");
	//
	//		bonusMesh->SetStaticMesh(Row->bonusMesh);
	//		GLog->Log(bonusMesh->GetStaticMesh()->GetName() + " ");
	//	}
}


