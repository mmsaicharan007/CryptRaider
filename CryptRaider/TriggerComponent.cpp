// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"
UTriggerComponent::UTriggerComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;
}
void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Display, TEXT("Hello from TriggerComponent BeginPlay!"));
	
}
void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){

    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    if (Mover == nullptr)
    {
        return;
    }

    AActor* Actor = GetOverlappingActor();
    if (Actor != nullptr)
    {
        UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
        if (Component != nullptr)
        {
            Component->SetSimulatePhysics(false);
        }
        Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
        Mover->SetShouldMove(true);
    }
    else
    {
        Mover->SetShouldMove(false);
    }

}
AActor* UTriggerComponent::GetOverlappingActor() const{
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);
    for (AActor* Actor : Actors)
    {
       
        bool HasAcceptableTag = Actor->ActorHasTag(AcceptableActorTag);
        bool IsGrabbed = Actor->ActorHasTag("Grabbed");
        if (HasAcceptableTag && !IsGrabbed)
        {
            return Actor; // Return the first actor that has the specified tag
        }
    }
    return nullptr; // No actor found with the specified tag
}
void UTriggerComponent::SetMover(UMover* NewMover)
{
    Mover = NewMover;
}
