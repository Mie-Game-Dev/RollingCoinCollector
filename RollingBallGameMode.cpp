#include "RollingBallGameMode.h"
#include "ScoreManager.h"
#include "RollingBall.h"
#include "RollingBallHUD.h"

ARollingBallGameMode::ARollingBallGameMode()
{
    ScoreManager = CreateDefaultSubobject<UScoreManager>(TEXT("ScoreManager"));
}

void ARollingBallGameMode::BeginPlay()
{
    Super::BeginPlay();

    if (URollingBallHUD* HUD = Cast<URollingBallHUD>(GetWorld()->GetFirstPlayerController()->GetHUD()))
    {
        ScoreManager->OnScoreUpdated.AddDynamic(HUD, &URollingBallHUD::UpdateScore);
    }
}

UScoreManager* ARollingBallGameMode::GetScoreManager() const
{
    return ScoreManager;
}