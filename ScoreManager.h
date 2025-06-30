#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ScoreManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreUpdated, int32, NewScore);

UCLASS(BlueprintType)
class ROLLINGCOINCOLLECTOR_API UScoreManager : public UObject
{
    GENERATED_BODY()

public:
    UScoreManager();

    UFUNCTION(BlueprintCallable, Category = "Score")
    void AddScore(int32 Value);

    UFUNCTION(BlueprintCallable, Category = "Score")
    int32 GetCurrentScore() const;

    UPROPERTY(BlueprintAssignable, Category = "Score")
    FOnScoreUpdated OnScoreUpdated;

private:
    UPROPERTY()
    int32 CurrentScore;
};