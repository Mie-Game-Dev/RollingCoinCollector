#include "Coin.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "RollingBall.h"

ACoin::ACoin()
{
    PrimaryActorTick.bCanEverTick = false;

    CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
    RootComponent = CollisionComponent;
    CollisionComponent->InitSphereRadius(30.0f);
    CollisionComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ACoin::OnBeginOverlap);

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComponent->SetupAttachment(RootComponent);
    MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ACoin::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    ARollingBall* Ball = Cast<ARollingBall>(OtherActor);
    if (Ball && OtherComp == Ball->FindComponentByClass<USphereComponent>())
    {
        Ball->GetScoreManager()->AddScore(ScoreValue);
        Destroy();
    }
}