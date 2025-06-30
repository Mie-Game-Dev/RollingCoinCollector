#include "RollingBallHUD.h"
#include "Components/TextBlock.h"

void URollingBallHUD::UpdateScore(int32 NewScore)
{
    if (ScoreText)
    {
        ScoreText->SetText(FText::AsNumber(NewScore));
    }
}