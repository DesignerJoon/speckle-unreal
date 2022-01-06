﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpeckleConverterComponent.generated.h"

class USpeckleConverter;
class ASpeckleUnrealManager;
class UBase;
class ISpeckleConverter;

UCLASS(ClassGroup=(Speckle), meta=(BlueprintSpawnableComponent))
class SPECKLEUNREAL_API USpeckleConverterComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	
	// A lazily initialised mapping of SpeckleType -> converters.
	TMap<FString, TScriptInterface<ISpeckleConverter>> SpeckleTypeMap;

public:
	
	// Array of converters
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Speckle|Conversion", meta=(DisplayThumbnail=true) )
	TArray<UObject*> SpeckleConverters;

	
	// Sets default values for this component's properties
	USpeckleConverterComponent();

	// Should be called after SpeckleConverters is modified  
	UFUNCTION(BlueprintCallable, Category="Speckle|Conversion")
	virtual void OnConvertersChangeHandler();
	
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent & PropertyChangedEvent) override;
#endif
	
	UFUNCTION(BlueprintCallable, Category="Speckle|Conversion")
	UBase* ConvertToSpeckle(UObject* Object);

	UFUNCTION(BlueprintCallable, Category="Speckle|Conversion")
	AActor* ConvertToNative(const UBase* Object, ASpeckleUnrealManager* Manager);
	
	UFUNCTION(BlueprintCallable, Category="Speckle|Conversion")
	TScriptInterface<ISpeckleConverter> GetConverter(const FString& SpeckleType);
};


