// Copyright (c) 2024 jawadato

#pragma once

#include "CoreMinimal.h"
#include "UnrealClient.h"
#include "Engine/Engine.h"
#include "Engine/GameViewportClient.h"
#include "Misc/FileHelper.h"
#include "Misc/App.h"
#include "Math/Color.h"
#include "Components/SkeletalMeshComponent.h"
#include "HAL/PlatformApplicationMisc.h"
#include "UObject/UObjectIterator.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NativeFunctionLibraryBPLibrary.generated.h"


UCLASS(Meta = (DisplayName = "Native Function Library"))
class UNativeFunctionLibraryBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

		//MARK: SortActorsByDistance
		/** 
		* Sorts an array of actors relative to distance to the provided actor from closest to furthest.
		* @param	RelativeTo Actor to sort against
		* @param	Array Array to sort
		* @return	Sorted Array from closest to furthest
		*/
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Actor", Meta = (Keywords = "SortActorsByDistance"))
		static void SortActorsByDistance(AActor* RelativeTo, TArray<AActor*> Array, TArray<AActor*>& ReturnValue);


		//MARK: SortActorsByDistance2D
		/** 
		* Sorts an array of actors relative to horizontal distance to the provided actor from closest to furthest.
		* @param	RelativeTo Actor to sort against
		* @param	Array Array to sort
		* @return	Sorted Array from closest to furthest		
		*/
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Actor", Meta = (Keywords = "SortActorsByDistance2D"))
		static void SortActorsByDistance2D(AActor* RelativeTo, TArray<AActor*> Array, TArray<AActor*>& ReturnValue);


		//MARK: SortActorsByLocation
		/** 
		* Sorts an array of actors relative to distance to the provided location vector from closest to furthest.
		* @param	RelativeTo Location to sort against
		* @param	Array Array to sort
		* @return	Sorted Array from closest to furthest				
		*/
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Actor", Meta = (Keywords = "SortActorsByLocation"))
		static void SortActorsByLocation(FVector RelativeTo, TArray<AActor*> Array, TArray<AActor*>& ReturnValue);


		//MARK: SortVectorsByDistance
		/** 
		* Sorts an array of vectors relative to distance to the provided location vector from closest to furthest.
		* @param	RelativeTo Location to sort against
		* @param	Array Array to sort
		* @return	Sorted Array from closest to furthest
		*/
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Vector", Meta = (Keywords = "SortVectorsByDistance"))
		static void SortVectorsByDistance(FVector RelativeTo, TArray<FVector> Array, TArray<FVector>& ReturnValue);


		//MARK: RandomVectorsInExtent
		/** 
		* Returns an array of random vectors distributed within a certain box extent from the origin, counting up to the provided amount.
		* @param	Amount Count of vectors
		* @param	InBoxExtent Extent of the rectangular volume
		* @param	Origin Origin of the volume
		* @return	Created vectors
		*/
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|Vector", Meta = (Keywords = "RandomVectorsInExtent"))
		static void RandomVectorsInBoxExtent(int32 Amount, FVector InBoxExtent, FVector Origin, TArray<FVector>& ReturnValue);


		//MARK: RandomVectorsInExtentFromStream
		/** 
		* Returns an array of random vectors distributed within a certain box extent from the origin, counting up to the provided amount.
		* @param	Amount Count of vectors
		* @param	InBoxExtent Extent of the rectangular volume
		* @param	Origin Origin of the volume
		* @param	Stream Random stream to use
		* @return	Created vectors
		*/
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|Vector", Meta = (Keywords = "RandomVectorsInExtentFromStream"))
		static void RandomVectorsInBoxExtentFromStream(int32 Amount, FVector InBoxExtent, FVector Origin, FRandomStream Stream, TArray<FVector>& ReturnValue);


		//MARK: AverageSeparationBetweenVectors
		/** 
		* Returns an arbitrary average separation value between an array of vectors, can be used to define arbitrary density of supplied vectors.
		* @param	Array Array which contains the vectors
		* @return	Calculated average separation value
		*/
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|Vector", Meta = (Keywords = "AverageSeparationBetweenVectors"))
		static void AverageSeparationBetweenVectors(TArray<FVector> Array, float& ReturnValue);		


		//MARK: NotNearLocations
		/** 
		* Compares an array of vectors against a provided location vector and returns true if none in the array is within a certain radius of the provided location vector.
		* @param	RelativeTo Location vector to compare against
		* @param	Array Array containing the vectors
		* @param	Radius Radius within which to query
		* @return	True or false based on query result
		*/		
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|Vector", Meta = (Keywords = "NotNearLocations"))
		static bool NotNearLocations(FVector RelativeTo, TArray<FVector> Array, float Radius);


		//MARK: PutAllRigidBodiesToSleep
		/** 
		* Force all bodies of associated skeletal mesh back to sleep.
		* @param	Mesh Skeletal Mesh which contains the simulating bones
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|SkeletalMesh", Meta = (Keywords = "PutAllRigidBodiesToSleep"))
		static void PutAllRigidBodiesToSleep(USkeletalMeshComponent* Mesh);		


		//MARK: ClearOnScreenDebugMessages
		/** 
		* Clears all on screen debug messages.
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Debug", Meta = (Keywords = "ClearOnScreenDebugMessages"))
		static void ClearOnScreenDebugMessages();


		//MARK: LaunchedWithCommandLineArgument
		/** 
		* Returns true if a specific command line flag was used during launch.
		* @param	Argument Command line argument to query against
		* @return	True or false based on query result
		*/		
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|CommandLine", Meta = (Keywords = "LaunchedWithCommandLineArgument"))
		static bool LaunchedWithCommandLineArgument(FString Argument = "");


		//MARK: StringToClipboard
		/** 
		* Copies the provided string into clipboard.
		* @param	String String which to copy
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Misc", Meta = (Keywords = "StringToClipboard"))
		static void StringToClipboard(const FString& String);


		//MARK: ClipboardToString
		/** 
		* Retrieves the contents of the clipboard into a string.
		* @return	String containing clipboard contents
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Misc", Meta = (Keywords = "ClipboardToString"))
		static FString ClipboardToString();


		//MARK: GetWorldObjectCount
		/** 
		* Retrieves the number of UObjects present in the world.
		* @return	UObject count
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Misc", Meta = (Keywords = "GetWorldObjectCount", WorldContext = "WorldContext"))
		static int32 GetWorldObjectCount(UObject* WorldContext);


		//MARK: HexToColor
		/** 
		* Converts provided Hex color code to a Color Structure.
		* @param	Hex Hex code which to convert
		* @return	Converted Color Structure
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|String", Meta = (Keywords = "HexToColor"))
		static FColor HexToColor(FString Hex);


		//MARK: ColorToHex
		/** 
		* Converts provided Color Structure into Hex color code.
		* @param	Color Color Structure which to convert
		* @return	Converted Hex String
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|String", Meta = (Keywords = "ColorToHex"))
		static FString ColorToHex(FColor Color);


		//MARK: StringToFile
		/** 
		* Writes provided String to a File.
		* @param	String String which to save
		* @param	Filename File path to use		
		* @return	Result of write operation
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|String", Meta = (Keywords = "StringToFile"))
		static bool StringToFile(FString String, const FString Filename);


		//MARK: StringArrayToFile
		/** 
		* Writes provided String Array to a File.
		* @param	Strings Strings to save
		* @param	Filename File path to use
		* @return	Result of write operation
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|String", Meta = (Keywords = "StringArrayToFile"))
		static bool StringArrayToFile(const TArray<FString>& Strings, const FString Filename);


		//MARK: FileToString
		/** 
		* Loads provided File into a String.
		* @param	String Loaded String
		* @param	Filename File path to use
		* @return	Result of read operation
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|String", Meta = (Keywords = "FileToString"))
		static bool FileToString(FString& String, const FString Filename);


		//MARK: FileToStringArray
		/** 
		* Loads provided File into a String Array.
		* @param	Strings Loaded Strings
		* @param	Filename File path to use
		* @return	Result of read operation
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|String", Meta = (Keywords = "FileToStringArray"))
		static bool FileToStringArray(TArray<FString>& Strings, const FString Filename);


		//MARK: StringArrayToSorted
		/** 
		* Creates a copy of the provided String Array then sorts the copy in ascending order and returns the value.
		* @param	Strings Strings to sort
		* @return	Result of sort operation
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|String", Meta = (Keywords = "StringArrayToSorted"))
		static TArray<FString> StringArrayToSorted(const TArray<FString>& Strings);


		//MARK: IntegerArrayToSorted
		/** 
		* Creates a copy of the provided Integer Array then sorts the copy in ascending order and returns the value.
		* @param	Integers Integers to sort
		* @return	Result of sort operation
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Integer", Meta = (Keywords = "IntegerArrayToSorted"))
		static TArray<int32> IntegerArrayToSorted(const TArray<int32>& Integers);


		//MARK: FloatArrayToSorted
		/** 
		* Creates a copy of the provided Float Array then sorts the copy in ascending order and returns the value.
		* @param	Floats Floats to sort
		* @return	Result of sort operation
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Float", Meta = (Keywords = "FloatArrayToSorted"))
		static TArray<float> FloatArrayToSorted(const TArray<float>& Floats);


		//MARK: CalculateMean
		/** 
		* Provided a dataset in form of a Float array, returns the Mean value.
		* @param	Data Float array to find Mean value within
		* @return	Mean value
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Statistics", Meta = (Keywords = "CalculateMean"))
		static float CalculateMean(const TArray<float>& Data);


		//MARK: CalculateWeightedMean
		/** 
		* Provided two Float arrays, returns the Weighted Mean value.
		* Both arrays must consist of equal amount of entries.
		* Weights are mapped onto data based on matching indices.
		* @param	Data Float array to find Weighted Mean value within
		* @param	Weights Float array comprising of weights needed to evaluate the data		
		* @return	Weighted Mean value
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Statistics", Meta = (Keywords = "CalculateWeightedMean"))
		static float CalculateWeightedMean(const TArray<float>& Data, const TArray<float>& Weights);


		//MARK: CalculateMedian
		/** 
		* Provided a dataset in form of a Float array, returns the Median value.
		* @param	Data Float array to find Median value within
		* @return	Median value
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Statistics", Meta = (Keywords = "CalculateMedian"))
		static float CalculateMedian(const TArray<float>& Data);


		//MARK: CalculateStatisticalRange
		/** 
		* Provided a dataset in form of a Float array, returns the Statistical Range value.
		* @param	Data Float array to find Range value within
		* @return	Range value
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Statistics", Meta = (Keywords = "CalculateStatisticalRange"))
		static float CalculateStatisticalRange(const TArray<float>& Data);	


		//MARK: CalculateStandardDeviation
		/** 
		* Provided a dataset in form of a Float array, returns the Standard Deviation value.
		* Optionally treat data as "Population" instead of "Sample".
		* @param	bPopulation Set true to treat data as "Population"; treat as "Sample" otherwise		
		* @param	Data Float array to find Standard Deviation value within
		* @return	Standard Deviation value
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Statistics", Meta = (Keywords = "CalculateStandardDeviation"))
		static float CalculateStandardDeviation(bool bPopulation, const TArray<float>& Data);	


		//MARK: CalculateStatisticalZScore
		/** 
		* Provided an Observed Value along with the Mean and Standard Deviation of a dataset, returns the Standard Score (Z-Score).
		* @param	ObservedValue Value to find Z-Score for
		* @param	Mean Mean value
		* @param	StandardDeviation Standard Deviation value
		* @return	Z-Score
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Statistics", Meta = (DisplayName = "Calculate Statistical Z-Score", Keywords = "CalculateStatisticalZScore"))
		static float CalculateStatisticalZScore(float ObservedValue, float Mean, float StandardDeviation);


		//MARK: CalculateRelativeRisk
		/** 
		* Provided a population size, how many develop a risk without exposure and how many do, returns the relative risk.
		* Optionally multiply by 100 to return the percentage figure.
		* @param	PopulationSize Size of the population
		* @param	WithoutExposure Subset of population without exposure or placebo (background) Subset
		* @param	WithExposure Subset of population with exposure
		* @param	bPercentage Multiply by 100
		* @return	Relative risk
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Statistics", Meta = (Keywords = "CalculateRelativeRisk"))
		static float CalculateRelativeRisk(float PopulationSize, float WithoutExposure, float WithExposure, bool bPercentage);


		//MARK: CalculateNumberOfPairs
		/** 
		* Provided the size of a finite set of elements, returns the number of pairs of elements.
		* Uses the Triangular Numbers method.
		* @param	NumberOfElements Amount of elements
		* @return	Number of element pairs
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Statistics", Meta = (Keywords = "CalculateNumberOfPairs"))
		static int32 CalculateNumberOfPairs(int32 NumberOfElements);


		//MARK: CalculateLikelihood
		/** 
		* Given the probability of an individual occurrence, returns the likelihood of said occurrence if repeated n times with the same probability.
		* Return a 0 to 1 percentage value.
		* @param	Probability Probability of an individual occurrence
		* @param	RepeatCount Likelihood of occurrence after trying this many times
		* @return	Likelihood
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Statistics", Meta = (Keywords = "CalculateLikelihood"))
		static float CalculateLikelihood(float Probability, int32 RepeatCount);


		//MARK: FlushInputs
		/** 
		* Flushes all accumulated inputs.
		* @param	PlayerController Player Controller which needs to be flushed
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Input", Meta = (Keywords = "FlushInputs"))
		static void FlushInputs(APlayerController* PlayerController);


		//MARK: GetInputHeldDuration
		/** 
		* Queries how long a particular input key has been held down for.
		* @param	PlayerController Player Controller which to query against
		* @param	Key Key to query
		* @return	Duration in seconds of how long the Key has been held for
		*/		
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|Input", Meta = (Keywords = "GetInputHeldDuration"))
		static float GetInputHeldDuration(APlayerController* PlayerController, FKey Key);		


		//MARK: GetHitResultAtScreenPosition
		/** 
		* Does a collision query at the provided position on the screen.
		* @param	PlayerController Player Controller to use
		* @param	ScreenPosition Screen position to trace at
		* @param	TraceChannel Trace collision channel to use
		* @param	bTraceComplex Should trace complex collision								
		* @param	HitResult Result of trace
		* @return	True or false depending on hit
		*/		
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|Player", Meta = (Keywords = "GetHitResultAtScreenPosition"))
		static bool GetHitResultAtScreenPosition(APlayerController* PlayerController, const FVector2D ScreenPosition, const ETraceTypeQuery TraceChannel, bool bTraceComplex, FHitResult& HitResult);
		

		//MARK: ClientFadeCamera
		/** 
		* Smoothly interpolates the camera to the provided Linear Color over a certain duration.
		* @param	PlayerController Player Controller to use
		* @param	bFadeAudio Should also fade audio
		* @param	bHoldWhenFinished Should retain fade color once alpha reaches stop value
		* @param	FadeColor Linear Color structure used for the fade
		* @param	FadeAlphaStart At alpha which to start the fade at
		* @param	FadeAlphaStop Alpha towards the fade interpolates to
		* @param	FadeDuration The interpolation duration in seconds
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Player", Meta = (Keywords = "ClientFadeCamera", AdvancedDisplay = "2"))
		static void ClientFadeCamera(APlayerController* PlayerController, bool bFadeAudio, bool bHoldWhenFinished, FLinearColor FadeColor = FLinearColor(0.0, 0.66, 1.0), float FadeAlphaStart = 0.f, float FadeAlphaStop = 1.f, float FadeDuration = 1.f);
		

		//MARK: LocationOnScreen
		/** 
		* Determines if provided location Vector is currently on screen relative to player camera.
		* @param	PlayerController Player Controller which to query against
		* @param	Location Location to query
		* @return	True or false based on query result
		*/			
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|Player", Meta=(Keywords = "LocationOnScreen"))
		static bool LocationOnScreen(APlayerController* PlayerController, FVector Location);
};