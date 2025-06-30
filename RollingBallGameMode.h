#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RollingBallGameMode.generated.h"

UCLASS()
class ROLLINGCOINCOLLECTOR_API ARollingBallGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ARollingBallGameMode();

    UFUNCTION(BlueprintCallable, Category = "Game")
    class UScoreManager* GetScoreManager() const;

protected:
    UPROPERTY()
    UScoreManager* ScoreManager;

    virtual void BeginPlay() override;
};