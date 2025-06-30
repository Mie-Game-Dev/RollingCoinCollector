#include "ScoreManager.h"

UScoreManager::UScoreManager()
{
    CurrentScore = 0;
}

void UScoreManager::AddScore(int32 Value)
{
    CurrentScore += Value;
    OnScoreUpdated.Broadcast(CurrentScore);
}

int32 UScoreManager::GetCurrentScore() const
{
    return CurrentScore;
}