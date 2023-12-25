// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NativeFunctionLibrary.generated.h"



/**
 * 
 */
UCLASS()
class PROJECT_API UNativeFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		//SortActorsByDistance
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Actor", Meta = (Keywords = "SortActorsByDistance"))
		static void SortActorsByDistance(AActor* RelativeTo, TArray<AActor*> inArray, TArray<AActor*>& outArray);


		//SortActorsByDistance2D
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Actor", Meta = (Keywords = "SortActorsByDistance2D"))
		static void SortActorsByDistance2D(AActor* RelativeTo, TArray<AActor*> inArray, TArray<AActor*>& outArray);


		//SortActorsByLocation
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Actor", Meta = (Keywords = "SortActorsByLocation"))
		static void SortActorsByLocation(FVector RelativeTo, TArray<AActor*> inArray, TArray<AActor*>& outArray);


		//SortVectorsByDistance
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Vector", Meta = (Keywords = "SortVectorsByDistance"))
		static void SortVectorsByDistance(FVector RelativeTo, TArray<FVector> inArray, TArray<FVector>& outArray);


		//NotNearLocations
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|Vector", Meta = (Keywords = "NotNearLocations"))
		static bool NotNearLocations(FVector RelativeTo, TArray<FVector> inArray, float Radius);		


		//PutAllRigidBodiesToSleep
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|SkeletalMesh", Meta = (Keywords = "PutAllRigidBodiesToSleep"))
		static void PutAllRigidBodiesToSleep(USkeletalMeshComponent* Mesh);


		//ClearOnScreenDebugMessages
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Debug", Meta = (Keywords = "ClearOnScreenDebugMessages"))
		static void ClearOnScreenDebugMessages();


		//IsCommandLineArgumentValid
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|CommandLine", Meta = (Keywords = "IsCommandLineArgumentValid"))
		static bool IsCommandLineArgumentValid(FString Argument = "");


		//StringToClipboard
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Misc", Meta = (Keywords = "StringToClipboard"))
		static void StringToClipboard(FString String);


		//ClipboardToString
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Misc", Meta = (Keywords = "ClipboardToString"))
		static void ClipboardToString(FString& String);


		//HexToColor
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|String", Meta = (Keywords = "HexToColor"))
		static FColor HexToColor(FString Hex);


		//ColorToHex
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|String", Meta = (Keywords = "ColorToHex"))
		static FString ColorToHex(FColor Color);		


		//FlushInputs
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Input", Meta = (Keywords = "FlushInputs"))
		static void FlushInputs(APlayerController* PlayerController);		
	
};
