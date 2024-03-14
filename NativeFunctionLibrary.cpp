#include "NativeFunctionLibrary.h"


//SortActorsByDistance
void UNativeFunctionLibrary::SortActorsByDistance(AActor* RelativeTo, TArray<AActor*> Array, TArray<AActor*>& ReturnValue) {

    Array.Sort([RelativeTo](const AActor& A, const AActor& B) {
        float DistanceA = A.GetSquaredDistanceTo(RelativeTo);
        float DistanceB = B.GetSquaredDistanceTo(RelativeTo);
        return DistanceA < DistanceB;
    });
    ReturnValue = Array;
}


//SortActorsByDistance2D
void UNativeFunctionLibrary::SortActorsByDistance2D(AActor* RelativeTo, TArray<AActor*> Array, TArray<AActor*>& ReturnValue) {

    Array.Sort([RelativeTo](const AActor& A, const AActor& B) {
        float DistanceA = A.GetHorizontalDistanceTo(RelativeTo);
        float DistanceB = B.GetHorizontalDistanceTo(RelativeTo);
        return DistanceA < DistanceB;
    });
    ReturnValue = Array;
}


//SortActorsByLocation
void UNativeFunctionLibrary::SortActorsByLocation(FVector RelativeTo, TArray<AActor*> Array, TArray<AActor*>& ReturnValue) {

    Array.Sort([RelativeTo](const AActor& A, const AActor& B) {
        float DistanceA = (A.GetActorLocation() - RelativeTo).Size();
        float DistanceB = (B.GetActorLocation() - RelativeTo).Size();
        return DistanceA < DistanceB;
    });
    ReturnValue = Array;
}


//SortVectorsByDistance
void UNativeFunctionLibrary::SortVectorsByDistance(FVector RelativeTo, TArray<FVector> Array, TArray<FVector>& ReturnValue) {

    Array.Sort([RelativeTo](const FVector& A, const FVector& B) {
        float DistanceA = FVector::DistSquared(A, RelativeTo);
        float DistanceB = FVector::DistSquared(B, RelativeTo);
        return DistanceA < DistanceB;
    });
    ReturnValue = Array;
}


//NotNearLocations
bool UNativeFunctionLibrary::NotNearLocations(FVector RelativeTo, TArray<FVector> Array, float Radius) {

    bool NotInRadius = true;
    float CurrentRadius = 0.f;
        for (FVector& Position : Array)
        {
            CurrentRadius = FVector::Dist(Position, RelativeTo);
            if (CurrentRadius <= Radius)
                {
                    NotInRadius = false;
                    break;
                }                         
        };
    return NotInRadius;
}


//PutAllRigidBodiesToSleep
void UNativeFunctionLibrary::PutAllRigidBodiesToSleep(USkeletalMeshComponent* Mesh) {

    if(!Mesh)
    {
       return;
    }

        Mesh->PutAllRigidBodiesToSleep();
    
    return;
}


//ClearOnScreenDebugMessages
void UNativeFunctionLibrary::ClearOnScreenDebugMessages() {
    
    GEngine->ClearOnScreenDebugMessages();
}


//IsCommandLineArgumentValid
bool UNativeFunctionLibrary::IsCommandLineArgumentValid(FString Argument) {

    return FParse::Param(FCommandLine::Get(), *Argument);
}


//StringToClipboard
void UNativeFunctionLibrary::StringToClipboard(FString String) {
 
    const TCHAR* TextToCopy = *String;
    FGenericPlatformMisc::ClipboardCopy(TextToCopy);
}


//ClipboardToString
void UNativeFunctionLibrary::ClipboardToString(FString& String) {
  
    FGenericPlatformMisc::ClipboardPaste(String);
}


//HexToColor
FColor UNativeFunctionLibrary::HexToColor(FString Hex) {
  
    return FColor::FromHex(Hex);
}


//ColorToHex
FString UNativeFunctionLibrary::ColorToHex(FColor Color) {
   
    return Color.ToHex();
}


//FlushInputs
void UNativeFunctionLibrary::FlushInputs(APlayerController* PlayerController) {
  
    PlayerController->FlushPressedKeys();
}
