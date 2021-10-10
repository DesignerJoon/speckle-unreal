// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpeckleUnrealActor.generated.h"

class UMeshDescriptionBase;

UCLASS(BlueprintType)
class SPECKLEUNREAL_API ASpeckleUnrealActor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere)
		USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* MeshComponent;
	
	FString NativeID;

	// Sets default values for this actor's properties
	ASpeckleUnrealActor();
	
    
	virtual void SetMesh(const TArray<FVector> &Vertices, const TArray<int32> &Triangles, TArray<FVector2D>& UV0, UMaterialInterface* Material);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
