#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Coin.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class ROLLINGCOINCOLLECTOR_API ACoin : public AActor
{
    GENERATED_BODY()

public:
    ACoin();

    UPROPERTY(EditAnywhere, Category = "Coin")
    int32 ScoreValue = 1;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USphereComponent* CollisionComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* MeshComponent;

    UFUNCTION()
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};