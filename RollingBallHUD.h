#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RollingBallHUD.generated.h"

UCLASS()
class ROLLINGCOINCOLLECTOR_API URollingBallHUD : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateScore(int32 NewScore);

protected:
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* ScoreText;
};