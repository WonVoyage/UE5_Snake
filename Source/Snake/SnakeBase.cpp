#include "SnakeBase.h"

//-------------------------------------------------------------------------------------------------------------
ASnakeBase::ASnakeBase()
	: Elements_Offset(100.0), Movement_Direction(EMovement_Direction::Up)
{
	PrimaryActorTick.bCanEverTick = true;
}
//-------------------------------------------------------------------------------------------------------------
void ASnakeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime);
}
//-------------------------------------------------------------------------------------------------------------
void ASnakeBase::Add_Snake_Element(int element_num)
{
	int i;

	for(i = 0; i < element_num; i++)
	{
		FVector new_location(Snake_Elements.Num() * Elements_Offset, 0, 0);
		FTransform new_transform(new_location);

		ASnake_Element *new_snake_element = GetWorld()->SpawnActor<ASnake_Element>(Snake_Element_Class, new_transform);
	
		new_snake_element->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
		Snake_Elements.Add(new_snake_element);
	}
}
//-------------------------------------------------------------------------------------------------------------
void ASnakeBase::Move(float delta_seconds)
{
	FVector movement_vector;
	float movement_speed = Speed * delta_seconds;

	switch (Movement_Direction)
	{
	case EMovement_Direction::Up:
		movement_vector.X += movement_speed;
		break;

	case EMovement_Direction::Down:
		movement_vector.X -= movement_speed;
		break;

	case EMovement_Direction::Left:
		movement_vector.Y += movement_speed;
		break;

	case EMovement_Direction::Right:
		movement_vector.Y -= movement_speed;
		break;
	}

	AddActorWorldOffset(movement_vector);
}
//-------------------------------------------------------------------------------------------------------------
void ASnakeBase::BeginPlay()
{
	Super::BeginPlay();
	Add_Snake_Element(4);
}
//-------------------------------------------------------------------------------------------------------------
