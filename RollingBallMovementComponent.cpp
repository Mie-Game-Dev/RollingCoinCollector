#include "RollingBallMovementComponent.h"
#include "Components/PrimitiveComponent.h"

URollingBallMovementComponent::URollingBallMovementComponent()
{
    UpdatedComponent = nullptr;
    Velocity = FVector::ZeroVector;
    PendingInput = FVector::ZeroVector;
}

void URollingBallMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    if (!UpdatedComponent || ShouldSkipUpdate(DeltaTime))
    {
        return;
    }

    ApplyControlInputToVelocity(DeltaTime);
    ApplyFriction(DeltaTime);
    ApplyGravity(DeltaTime);

    FVector MoveDelta = Velocity * DeltaTime;

    if (!MoveDelta.IsNearlyZero())
    {
        FHitResult Hit;
        SafeMoveUpdatedComponent(MoveDelta, UpdatedComponent->GetComponentRotation(), true, Hit);

        if (Hit.IsValidBlockingHit())
        {
            SlideAlongSurface(MoveDelta, 1.0f - Hit.Time, Hit.Normal, Hit);
        }
    }

    PendingInput = FVector::ZeroVector;
}

void URollingBallMovementComponent::AddInputVector(FVector WorldVector)
{
    PendingInput += WorldVector;
}

void URollingBallMovementComponent::ApplyControlInputToVelocity(float DeltaTime)
{
    FVector DesiredMovement = PendingInput.GetClampedToMaxSize(1.0f) * Acceleration * DeltaTime;
    Velocity += DesiredMovement;

    float CurrentSpeed = Velocity.Size();
    if (CurrentSpeed > MaxSpeed)
    {
        Velocity = Velocity.GetSafeNormal() * MaxSpeed;
    }
}

void URollingBallMovementComponent::ApplyFriction(float DeltaTime)
{
    Velocity = Velocity * FMath::Max(0.0f, 1.0f - FMath::Min(1.0f, Friction * DeltaTime));
}

void URollingBallMovementComponent::ApplyGravity(float DeltaTime)
{
    if (UpdatedComponent)
    {
        Velocity.Z -= GetGravityZ() * GravityScale * DeltaTime;
    }
}