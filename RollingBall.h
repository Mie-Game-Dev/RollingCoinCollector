#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RollingBall.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class URollingBallMovementComponent;
class UScoreManager;
class ARollingBallGameMode;

UCLASS()
class ROLLINGCOINCOLLECTOR_API ARollingBall : public APawn
{
    GENERATED_BODY()

public:
    ARollingBall();

    UFUNCTION(BlueprintCallable, Category = "Score")
    UScoreManager* GetScoreManager() const;

protected:
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    USphereComponent* CollisionComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    UStaticMeshComponent* MeshComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    URollingBallMovementComponent* MovementComponent;

    void MoveForward(float Value);
    void MoveRight(float Value);
};