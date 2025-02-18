// Copyright (c) 2024 jawadato

#include "NativeFunctionLibraryBPLibrary.h"
#include "NativeFunctionLibrary.h"


UNativeFunctionLibraryBPLibrary::UNativeFunctionLibraryBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

//MARK: SortActorsByDistance
void UNativeFunctionLibraryBPLibrary::SortActorsByDistance(AActor* RelativeTo, TArray<AActor*> Array, TArray<AActor*>& ReturnValue)
{
    Array.Sort([RelativeTo](const AActor& A, const AActor& B)
    {
        float DistanceA = A.GetSquaredDistanceTo(RelativeTo);
        float DistanceB = B.GetSquaredDistanceTo(RelativeTo);

        return DistanceA < DistanceB;
    });

    ReturnValue = Array;
}


//MARK: SortActorsByDistance2D
void UNativeFunctionLibraryBPLibrary::SortActorsByDistance2D(AActor* RelativeTo, TArray<AActor*> Array, TArray<AActor*>& ReturnValue)
{
    Array.Sort([RelativeTo](const AActor& A, const AActor& B)
    {
        float DistanceA = A.GetHorizontalDistanceTo(RelativeTo);
        float DistanceB = B.GetHorizontalDistanceTo(RelativeTo);

        return DistanceA < DistanceB;
    });

    ReturnValue = Array;
}


//MARK: SortActorsByLocation
void UNativeFunctionLibraryBPLibrary::SortActorsByLocation(FVector RelativeTo, TArray<AActor*> Array, TArray<AActor*>& ReturnValue)
{
    Array.Sort([RelativeTo](const AActor& A, const AActor& B)
    {
        float DistanceA = (A.GetActorLocation() - RelativeTo).Size();
        float DistanceB = (B.GetActorLocation() - RelativeTo).Size();

        return DistanceA < DistanceB;
    });

    ReturnValue = Array;
}


//MARK: SortVectorsByDistance
void UNativeFunctionLibraryBPLibrary::SortVectorsByDistance(FVector RelativeTo, TArray<FVector> Array, TArray<FVector>& ReturnValue)
{
    Array.Sort([RelativeTo](const FVector& A, const FVector& B)
    {
        float DistanceA = FVector::DistSquared(A, RelativeTo);
        float DistanceB = FVector::DistSquared(B, RelativeTo);

        return DistanceA < DistanceB;
    });

    ReturnValue = Array;
}


//MARK: RandomVectorsInExtent
void UNativeFunctionLibraryBPLibrary::RandomVectorsInBoxExtent(int32 Amount, FVector InBoxExtent, FVector Origin, TArray<FVector>& ReturnValue)
{
    TArray<FVector> Vectors;

    for (int32 i = 0; i < Amount; ++i)
    {
        FVector Vector;
        Vector.X = FMath::RandRange(-InBoxExtent.X, InBoxExtent.X);
        Vector.Y = FMath::RandRange(-InBoxExtent.Y, InBoxExtent.Y);
        Vector.Z = FMath::RandRange(-InBoxExtent.Z, InBoxExtent.Z);
        Vectors.Add(Vector + Origin);
    }

    ReturnValue = Vectors;
}


//MARK: RandomVectorsInExtentFromStream
void UNativeFunctionLibraryBPLibrary::RandomVectorsInBoxExtentFromStream(int32 Amount, FVector InBoxExtent, FVector Origin, FRandomStream Stream, TArray<FVector>& ReturnValue)
{
    TArray<FVector> Vectors;

    for (int32 i = 0; i < Amount; ++i)
    {
        FVector Vector;
        Vector.X = Stream.FRandRange(-InBoxExtent.X, InBoxExtent.X);
        Vector.Y = Stream.FRandRange(-InBoxExtent.Y, InBoxExtent.Y);
        Vector.Z = Stream.FRandRange(-InBoxExtent.Z, InBoxExtent.Z);
        Vectors.Add(Vector + Origin);
    }

    ReturnValue = Vectors;
}


//MARK: AverageSeparationBetweenVectors
void UNativeFunctionLibraryBPLibrary::AverageSeparationBetweenVectors(TArray<FVector> Array, float& ReturnValue)
{
    float TotalDistance = 0.f;
    const int32 NumVectors = Array.Num();
    for (int32 i = 0; i < NumVectors; ++i)
    {
        for (int32 j = i + 1; j < NumVectors; ++j)
        {
            const FVector& VectorI = Array[i];
            const FVector& VectorJ = Array[j];
            const float Distance = FVector::Dist(VectorI, VectorJ);

            TotalDistance += Distance;
        }
    }

    ReturnValue = (TotalDistance / (NumVectors * (NumVectors - 1))) * 2;
}


//MARK: NotNearLocations
bool UNativeFunctionLibraryBPLibrary::NotNearLocations(FVector RelativeTo, TArray<FVector> Array, float Radius)
{
    bool bNotInRadius = true;
    float CurrentRadius = 0.f;

        for (FVector& Position : Array)
        {
            CurrentRadius = FVector::Dist(Position, RelativeTo);
            if (CurrentRadius <= Radius)
                {
                    bNotInRadius = false;
                    break;
                }                         
        };

    return bNotInRadius;
}


//MARK: PutAllRigidBodiesToSleep
void UNativeFunctionLibraryBPLibrary::PutAllRigidBodiesToSleep(USkeletalMeshComponent* Mesh)
{
    if (!Mesh)
    {
       return;
    }

        Mesh->PutAllRigidBodiesToSleep();
    
    return;
}


//MARK: ClearOnScreenDebugMessages
void UNativeFunctionLibraryBPLibrary::ClearOnScreenDebugMessages()
{
    GEngine->ClearOnScreenDebugMessages();
}


//MARK: LaunchedWithCommandLineArgument
bool UNativeFunctionLibraryBPLibrary::LaunchedWithCommandLineArgument(FString Argument)
{
    return FParse::Param(FCommandLine::Get(), *Argument);
}


//MARK: StringToClipboard
void UNativeFunctionLibraryBPLibrary::StringToClipboard(const FString& String)
{
    FPlatformApplicationMisc::ClipboardCopy(*String);
}


//MARK: ClipboardToString
FString UNativeFunctionLibraryBPLibrary::ClipboardToString()
{
    FString String;

    FPlatformApplicationMisc::ClipboardPaste(String);
 
    return String;
}

//MARK: GetWorldObjectCount
int32 UNativeFunctionLibraryBPLibrary::GetWorldObjectCount(UObject* WorldContext)
{ 
    int32 Count = 0;

    for (TObjectIterator<UObject> ObjectIterator; ObjectIterator; ++ObjectIterator)
    {
        if (ObjectIterator->GetWorld() == WorldContext ->GetWorld())
        {
            UObject* ObjectModel = *ObjectIterator;
            Count ++;
        }
    }
    
    return Count;
}


//MARK: HexToColor
FColor UNativeFunctionLibraryBPLibrary::HexToColor(FString Hex)
{
    return FColor::FromHex(Hex);
}


//MARK: ColorToHex
FString UNativeFunctionLibraryBPLibrary::ColorToHex(FColor Color)
{
    return Color.ToHex();
}


//MARK: StringToFile
bool UNativeFunctionLibraryBPLibrary::StringToFile(FString String, const FString Filename)
{
    const TCHAR* FilePath = *Filename;

    return FFileHelper::SaveStringToFile(String, FilePath);
}


//MARK: StringArrayToFile
bool UNativeFunctionLibraryBPLibrary::StringArrayToFile(const TArray<FString>& Strings, const FString Filename)
{
    const TCHAR* FilePath = *Filename;

    return FFileHelper::SaveStringArrayToFile(Strings, FilePath);
}


//MARK: FileToString
bool UNativeFunctionLibraryBPLibrary::FileToString(FString& String, const FString Filename)
{
    const TCHAR* FilePath = *Filename;

    return FFileHelper::LoadFileToString(String, FilePath);
}


//MARK: FileToStringArray
bool UNativeFunctionLibraryBPLibrary::FileToStringArray(TArray<FString>& Strings, const FString Filename)
{
    const TCHAR* FilePath = *Filename;

    return FFileHelper::LoadFileToStringArray(Strings, FilePath);
}


//MARK: StringArrayToSorted
TArray<FString> UNativeFunctionLibraryBPLibrary::StringArrayToSorted(const TArray<FString>& Strings)
{
    TArray<FString> SortedArray = Strings;
    SortedArray.Sort();
    return SortedArray;
}


//MARK: IntegerArrayToSorted
TArray<int32> UNativeFunctionLibraryBPLibrary::IntegerArrayToSorted(const TArray<int32>& Integers)
{
    TArray<int32> SortedArray = Integers;
    SortedArray.Sort();
    return SortedArray;
}


//MARK: FloatArrayToSorted
TArray<float> UNativeFunctionLibraryBPLibrary::FloatArrayToSorted(const TArray<float>& Floats)
{
    TArray<float> SortedArray = Floats;
    SortedArray.Sort();
    return SortedArray;
}


//MARK: CalculateMean
float UNativeFunctionLibraryBPLibrary::CalculateMean(const TArray<float>& Data)
{
    int32 NumberOfElements = Data.Num();

    if (NumberOfElements > 0)
    {
        float TotalValue = 0.f;

        for (int32 i = 0; i < NumberOfElements; ++i)
        {
            TotalValue += Data[i];
        }

        return TotalValue / NumberOfElements;
    }
    else
    {
        return 0.f;
    }
}


//MARK: CalculateWeightedMean
float UNativeFunctionLibraryBPLibrary::CalculateWeightedMean(const TArray<float>& Data, const TArray<float>& Weights)
{
    int32 NumberOfWeightElements = Weights.Num();
    int32 NumberOfDataElements = Data.Num();
    float Divisor = 0.f;

    if ((NumberOfDataElements > 0) && (NumberOfWeightElements == NumberOfDataElements))
    {
        float TotalValue = 0.f;

        for (int32 i = 0; i < NumberOfDataElements; ++i)
        {
            TotalValue += (Data[i] * Weights[i]);
        }       
        for (int32 i = 0; i < NumberOfDataElements; ++i)
        {
            Divisor += Weights[i];
        }

        return TotalValue / Divisor;
    }
    else
    {
        return 0.f;
    }
}


//MARK: CalculateMedian
float UNativeFunctionLibraryBPLibrary::CalculateMedian(const TArray<float>& Data)
{
    TArray<float> SortedData = Data;

    SortedData.Sort();

    int32 NumberOfElements = SortedData.Num();  
    float MedianValue = 0.f;

    if (NumberOfElements > 1)
    {
        bool bIsEven = false;

        if (NumberOfElements % 2 == 0)
        {
            bIsEven = true;
        }

        if (bIsEven)
        {
            int32 IndexA = NumberOfElements / 2;
            int32 IndexB = IndexA - 1;

            MedianValue = (SortedData[IndexA] + SortedData[IndexB]) / 2;
        }
        else
        {
            int32 MedianIndex = (NumberOfElements - 1) / 2;

            MedianValue = SortedData[MedianIndex];
        }
    }

    return MedianValue;
}


//MARK: CalculateStatisticalRange
float UNativeFunctionLibraryBPLibrary::CalculateStatisticalRange(const TArray<float>& Data)
{
    if (Data.Num() > 1)
    {
        return FMath::Max(Data) - FMath::Min(Data);
    }
    else
    {
        return 0.f;
    }
}


//MARK: CalculateStandardDeviation
float UNativeFunctionLibraryBPLibrary::CalculateStandardDeviation(bool bPopulation, const TArray<float>& Data)
{
    int32 n = Data.Num();
    float x = 0.f;
    float XSquared = 0.f;
    float SquaredSum = 0.f;
    float Divisor = 0.f;

    for (int32 i = 0; i < n; ++i)
    {
        x += Data[i];
    }

    XSquared = FMath::Square(x);

    for (int32 i = 0; i < n; ++i)
    {
        SquaredSum += FMath::Square(Data[i]);
    }

    if (bPopulation)
    {
        Divisor = FMath::Square(n);
    }
    else
    {
        Divisor = (n * (n - 1));
    }

    return FMath::Sqrt(((n * SquaredSum) - XSquared) / Divisor);
}


//MARK: CalculateStatisticalZScore
float UNativeFunctionLibraryBPLibrary::CalculateStatisticalZScore(float ObservedValue, float Mean, float StandardDeviation)
{
    return (ObservedValue - Mean) / StandardDeviation;
}


//MARK: CalculateRelativeRisk
float UNativeFunctionLibraryBPLibrary::CalculateRelativeRisk(float PopulationSize, float WithoutExposure, float WithExposure, bool bPercentage)
{
    float RiskB = WithoutExposure / PopulationSize;
    float RiskA = WithExposure / PopulationSize;
    float RiskR = RiskA / RiskB;

    if (bPercentage)
    {
        return RiskR * 100;
    }
    else
    {
        return RiskR;
    }
}


//MARK: CalculateNumberOfPairs
int32 UNativeFunctionLibraryBPLibrary::CalculateNumberOfPairs(int32 NumberOfElements)
{
    if (NumberOfElements > 1)
    {
    int32 nX = NumberOfElements;
    int32 nY = nX - 1;

    return (nX * nY) / 2;
    }
    else
    {
        return 0;
    }
}


//MARK: CalculateLikelihood
float UNativeFunctionLibraryBPLibrary::CalculateLikelihood(float Probability, int32 RepeatCount)
{
    float p = 1.0f - Probability;

    if (RepeatCount > 0 && p > 0.f && p < 1.0f)
    {
        return 1.0f - (FMath::Pow(p, RepeatCount));
    }
    else
    {
        return 1.0f - p;
    }
}


//MARK: FlushInputs
void UNativeFunctionLibraryBPLibrary::FlushInputs(APlayerController* PlayerController)
{
    PlayerController->FlushPressedKeys();
}


//MARK: GetInputHeldDuration
float UNativeFunctionLibraryBPLibrary::GetInputHeldDuration(APlayerController* PlayerController, FKey Key)
{
    return PlayerController->GetInputKeyTimeDown(Key);
}


//MARK: GetHitResultAtScreenPosition
bool UNativeFunctionLibraryBPLibrary::GetHitResultAtScreenPosition(APlayerController* PlayerController, const FVector2D ScreenPosition, const ETraceTypeQuery TraceChannel, bool bTraceComplex, FHitResult& HitResult)
{
    return PlayerController->GetHitResultAtScreenPosition(ScreenPosition, TraceChannel, bTraceComplex, HitResult);
}


//MARK: ClientFadeCamera
void UNativeFunctionLibraryBPLibrary::ClientFadeCamera(APlayerController* PlayerController, bool bFadeAudio, bool bHoldWhenFinished, FLinearColor FadeColor, float FadeAlphaStart, float FadeAlphaStop, float FadeDuration)
{
    FColor ConvertedFadeColor = FadeColor.ToFColor(true);
    FVector2D FadeAlpha = FVector2D(FadeAlphaStart, FadeAlphaStop);

    PlayerController->ClientSetCameraFade(true, ConvertedFadeColor, FadeAlpha, FadeDuration, bFadeAudio, bHoldWhenFinished);
}


//MARK: LocationOnScreen
bool UNativeFunctionLibraryBPLibrary::LocationOnScreen(APlayerController* PlayerController, FVector Location)

{
    if (!GEngine && !PlayerController)
    {
        return false;
    } 

    const FVector2D ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());

    FVector CameraLocation;
    FRotator CameraRotation;

    PlayerController->GetPlayerViewPoint(CameraLocation, CameraRotation);

    const FVector Direction = Location - CameraLocation;
    FVector ForwardVector = CameraRotation.Vector();
    FVector NormalizedDirection = Direction.GetSafeNormal();

    float DotProduct = FVector::DotProduct(ForwardVector, NormalizedDirection);
    bool bBehindCamera = (DotProduct < 0);
    FVector2D ScreenPosition = FVector2D();    

    if (bBehindCamera)
    {
        FVector NewLocation = CameraLocation + Direction * -1.f;

        PlayerController->ProjectWorldLocationToScreen(NewLocation, ScreenPosition);

        ScreenPosition.X = ViewportSize.X - ScreenPosition.X;
        ScreenPosition.Y = ViewportSize.Y - ScreenPosition.Y;
    }
    else
    {
       PlayerController->ProjectWorldLocationToScreen(Location, ScreenPosition);
    }

    if (ScreenPosition.X >= 0.f && ScreenPosition.X <= ViewportSize.X && ScreenPosition.Y >= 0.f && ScreenPosition.Y <= ViewportSize.Y && !bBehindCamera)
    {
        return true;
    }

	return false;
}