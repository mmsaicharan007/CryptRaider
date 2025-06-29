// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	void Release(); // Release the currently held object
	UFUNCTION(BlueprintCallable)
	void Grab();
	UPROPERTY(EditAnywhere)
	float MaxGrabDistance = 400.f; // Maximum distance for grabbing objects
	UPROPERTY(EditAnywhere)
	float GrabRadius = 100;	
	UPROPERTY(EditAnywhere)
	float HoldDistance = 200.f; // Distance to hold the grabbed object from the player

	UPhysicsHandleComponent* GetPhysicsHandle() const;
	bool GetGrabbableInReach(FHitResult& OutHitResult) const;
};
