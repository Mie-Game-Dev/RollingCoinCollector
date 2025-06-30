#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "RollingBallMovementComponent.generated.h"

UCLASS()
class ROLLINGCOINCOLLECTOR_API URollingBallMovementComponent : public UPawnMovementComponent
{
    GENERATED_BODY()

public:
    URollingBallMovementComponent();

    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float MaxSpeed = 1000.0f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float Acceleration = 2000.0f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float Friction = 5.0f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float GravityScale = 1.0f;

    void AddInputVector(FVector WorldVector) override;

protected:
    FVector PendingInput;
    FVector Velocity;

    virtual void ApplyControlInputToVelocity(float DeltaTime);
    virtual void ApplyFriction(float DeltaTime);
    virtual void ApplyGravity(float DeltaTime);
};