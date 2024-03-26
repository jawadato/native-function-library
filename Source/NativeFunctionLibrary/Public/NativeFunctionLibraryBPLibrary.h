// © 2024 jawadato

#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "HAL/PlatformApplicationMisc.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NativeFunctionLibraryBPLibrary.generated.h"

UCLASS()
class UNativeFunctionLibraryBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

		//SortActorsByDistance
		/** 
		* Sorts an array of actors relative to distance to the provided actor from closest to furthest.
		*/
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Actor", Meta = (Keywords = "SortActorsByDistance"))
		static void SortActorsByDistance(AActor* RelativeTo, TArray<AActor*> Array, TArray<AActor*>& ReturnValue);


		//SortActorsByDistance2D
		/** 
		* Sorts an array of actors relative to horizontal distance to the provided actor from closest to furthest.
		*/
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Actor", Meta = (Keywords = "SortActorsByDistance2D"))
		static void SortActorsByDistance2D(AActor* RelativeTo, TArray<AActor*> Array, TArray<AActor*>& ReturnValue);


		//SortActorsByLocation
		/** 
		* Sorts an array of actors relative to distance to the provided location vector from closest to furthest.
		*/
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Actor", Meta = (Keywords = "SortActorsByLocation"))
		static void SortActorsByLocation(FVector RelativeTo, TArray<AActor*> Array, TArray<AActor*>& ReturnValue);


		//SortVectorsByDistance
		/** 
		* Sorts an array of vectors relative to distance to the provided location vector from closest to furthest.
		*/
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Vector", Meta = (Keywords = "SortVectorsByDistance"))
		static void SortVectorsByDistance(FVector RelativeTo, TArray<FVector> Array, TArray<FVector>& ReturnValue);


		//RandomVectorsInExtent
		/** 
		* Returns an array of random vectors distributed within a certain box extent from the origin, counting up to the provided amount.
		*/
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|Vector", Meta = (Keywords = "RandomVectorsInExtent"))
		static void RandomVectorsInBoxExtent(int32 Amount, FVector InBoxExtent, FVector Origin, TArray<FVector>& ReturnValue);


		//RandomVectorsInExtentFromStream
		/** 
		* Returns an array of random vectors distributed within a certain box extent from the origin, counting up to the provided amount.
		*/
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|Vector", Meta = (Keywords = "RandomVectorsInExtentFromStream"))
		static void RandomVectorsInBoxExtentFromStream(int32 Amount, FVector InBoxExtent, FVector Origin, FRandomStream Stream, TArray<FVector>& ReturnValue);


		//AverageSeparationBetweenVectors
		/** 
		* Returns an arbitrary average separation value between an array of vectors, can be used to define arbitrary density of supplied vectors.
		*/
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|Vector", Meta = (Keywords = "AverageSeparationBetweenVectors"))
		static void AverageSeparationBetweenVectors(TArray<FVector> Array, float& ReturnValue);		


		//NotNearLocations
		/** 
		* Compares an array of vectors against a provided location vector and returns true if none in the array is within a certain radius of the provided location vector.
		*/		
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|Vector", Meta = (Keywords = "NotNearLocations"))
		static bool NotNearLocations(FVector RelativeTo, TArray<FVector> Array, float Radius);


		//PutAllRigidBodiesToSleep
		/** 
		* Force all bodies of associated skeletal mesh back to sleep.
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|SkeletalMesh", Meta = (Keywords = "PutAllRigidBodiesToSleep"))
		static void PutAllRigidBodiesToSleep(USkeletalMeshComponent* Mesh);


		//ClearOnScreenDebugMessages
		/** 
		* Clears all on screen debug messages.
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Debug", Meta = (Keywords = "ClearOnScreenDebugMessages"))
		static void ClearOnScreenDebugMessages();


		//LaunchedWithCommandLineArgument
		/** 
		* Returns true if a specific command line flag was used during launch.
		*/		
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|CommandLine", Meta = (Keywords = "LaunchedWithCommandLineArgument"))
		static bool LaunchedWithCommandLineArgument(FString Argument = "");


		//StringToClipboard
		/** 
		* Copies the provided string into clipboard.
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Misc", Meta = (Keywords = "StringToClipboard"))
		static void StringToClipboard(const FString& String);


		//ClipboardToString
		/** 
		* Retrieves the contents of the clipboard into a string.
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Misc", Meta = (Keywords = "ClipboardToString"))
		static void ClipboardToString(FString& String);


		//HexToColor
		/** 
		* Converts provided Hex color code to a Color Structure.
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|String", Meta = (Keywords = "HexToColor"))
		static FColor HexToColor(FString Hex);


		//ColorToHex
		/** 
		* Converts provided Color Structure into Hex color code.
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|String", Meta = (Keywords = "ColorToHex"))
		static FString ColorToHex(FColor Color);


		//FlushInputs
		/** 
		* Flushes all accumulated inputs.
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Input", Meta = (Keywords = "FlushInputs"))
		static void FlushInputs(APlayerController* PlayerController);		
};