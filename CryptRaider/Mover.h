// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Mover.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UMover : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMover();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	AActor* Owner = GetOwner();
	public:
	void SetShouldMove(bool ShouldMove);
	public:
	UPROPERTY(EditAnywhere)
	FVector MoveOffSet;
	UPROPERTY(EditAnywhere)
	float MoveSpeed = 4;

	bool ShouldMove = false;
	
	FVector StartLocation;
};
