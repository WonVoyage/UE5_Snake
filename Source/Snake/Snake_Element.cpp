#include "Snake_Element.h"

//-------------------------------------------------------------------------------------------------------------
ASnake_Element::ASnake_Element()
{
	PrimaryActorTick.bCanEverTick = true;
	Snake_Element_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Snake_Element_Mesh"));
}
//-------------------------------------------------------------------------------------------------------------
void ASnake_Element::BeginPlay()
{
	Super::BeginPlay();	
}
//-------------------------------------------------------------------------------------------------------------
void ASnake_Element::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
//-------------------------------------------------------------------------------------------------------------
