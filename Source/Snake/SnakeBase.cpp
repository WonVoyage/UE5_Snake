#include "SnakeBase.h"

//-------------------------------------------------------------------------------------------------------------
ASnakeBase::ASnakeBase()
	: Elements_Offset(200.0), Speed(10.0), Movement_Direction(EMovement_Direction::Up)
{
	PrimaryActorTick.bCanEverTick = true;
}
//-------------------------------------------------------------------------------------------------------------
void ASnakeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
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
		//new_snake_element->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
		Snake_Elements.Add(new_snake_element);
	}
}
//-------------------------------------------------------------------------------------------------------------
void ASnakeBase::Move()
{
	float movement_speed = Elements_Offset;
	FVector movement_vector(ForceInitToZero);
	
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

	default:
		break;
	}

	//AddActorWorldOffset(movement_vector);
	for (	int i = Snake_Elements.Num() - 1; i > 0; i--)
	{
		auto curr_element = Snake_Elements[i];
		auto prev_element = Snake_Elements[i - 1];
		FVector prev_location = prev_element->GetActorLocation();
		curr_element->SetActorLocation(prev_location);
	}

	Snake_Elements[0]->AddActorWorldOffset(movement_vector);
	this->AddActorWorldOffset(movement_vector);

}
//-------------------------------------------------------------------------------------------------------------
void ASnakeBase::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickInterval(Speed);
	Add_Snake_Element(5);
}
//-------------------------------------------------------------------------------------------------------------
