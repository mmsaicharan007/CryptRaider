// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Mover.h"
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "TriggerComponent.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UTriggerComponent : public UBoxComponent
{
	public:
	UTriggerComponent();

	GENERATED_BODY()
	protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	void SetMover(UMover* Mover);
	private:
	AActor* GetOverlappingActor() const;
	UPROPERTY(EditAnywhere)
	FName TriggerTag = "UnlockDoor1"; // Tag to identify the trigger for unlocking doors
	private:
	UPROPERTY(EditAnywhere)
	FName AcceptableActorTag;

	UMover* Mover;

};
