#include "RollingBall.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "RollingBallMovementComponent.h"
#include "RollingBallGameMode.h"
#include "ScoreManager.h"

ARollingBall::ARollingBall()
{
    PrimaryActorTick.bCanEverTick = false;

    CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
    RootComponent = CollisionComponent;
    CollisionComponent->InitSphereRadius(40.0f);
    CollisionComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComponent->SetupAttachment(RootComponent);
    MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    MovementComponent = CreateDefaultSubobject<URollingBallMovementComponent>(TEXT("MovementComponent"));
    MovementComponent->UpdatedComponent = RootComponent;
}

void ARollingBall::BeginPlay()
{
    Super::BeginPlay();
}

void ARollingBall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ARollingBall::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ARollingBall::MoveRight);
}

UScoreManager* ARollingBall::GetScoreManager() const
{
    if (const ARollingBallGameMode* GameMode = Cast<ARollingBallGameMode>(GetWorld()->GetAuthGameMode()))
    {
        return GameMode->GetScoreManager();
    }
    return nullptr;
}

void ARollingBall::MoveForward(float Value)
{
    if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent))
    {
        MovementComponent->AddInputVector(GetActorForwardVector() * Value);
    }
}

void ARollingBall::MoveRight(float Value)
{
    if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent))
    {
        MovementComponent->AddInputVector(GetActorRightVector() * Value);
    }
}