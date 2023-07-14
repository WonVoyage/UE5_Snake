#include "SnakeBase.h"

//-------------------------------------------------------------------------------------------------------------
ASnakeBase::ASnakeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}
//-------------------------------------------------------------------------------------------------------------
void ASnakeBase::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->SpawnActor<ASnake_Element>(Snake_Element_Class, GetActorTransform());
}
//-------------------------------------------------------------------------------------------------------------
void ASnakeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
//-------------------------------------------------------------------------------------------------------------