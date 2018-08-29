// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/DataTable.h"

#include "PM_GridCell.generated.h"

UENUM(BlueprintType)
enum class ECellPurpose : uint8 
{
	P_Empty UMETA(DisplayName = "Empty"),
	P_Block UMETA(DisplayName = "Block"),
	P_Regular UMETA(DisplayName = "Regular"),
	P_Extra UMETA(DisplayName = "Extra"),
	P_Fruit UMETA(DisplayName = "Fruit")
};

USTRUCT(Blueprintable)
struct FCellInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "CellType")
	ECellPurpose cellPurpose;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "CellType")
	int scorePoints;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "CellType")
	UStaticMesh* bonusMesh = nullptr;
};

UCLASS()
class PACKMANGAME_API APM_GridCell : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APM_GridCell();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Cell")
	UBoxComponent* boxCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Cell")
	UStaticMeshComponent* bonusMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cell")
	UDataTable* InfoDataTable;

	UFUNCTION(BlueprintCallable, Category = "CellInfo")
	int GetScorePoints();
	
	UFUNCTION(BlueprintCallable, Category = "CallInfo")
	ECellPurpose GetCellPurpose();

	UFUNCTION(BlueprintCallable, Category = "CellInfo")
	bool CheckIsPicked();

	UFUNCTION(BlueprintCallable, Category = "CallInfo")
	bool CheckIsOcupied();

	UFUNCTION(BlueprintCallable, Category = "CallInfo")
	void Pick();

private:

	void SetInitialCellValues();

	ECellPurpose cellPurpose;
	int scorePoints;
	bool isPicked;	
	bool isOccupied;
};
