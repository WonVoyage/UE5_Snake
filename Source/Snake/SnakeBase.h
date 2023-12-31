#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Snake_Element.h"
#include "SnakeBase.generated.h"

//-------------------------------------------------------------------------------------------------------------
UENUM()
enum class EMovement_Direction
{
	Up,
	Down,
	Left,
	Right
};
//-------------------------------------------------------------------------------------------------------------
UCLASS()
class SNAKE_API ASnakeBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ASnakeBase();

	virtual void Tick(float DeltaTime);

	void Add_Snake_Element(int element_num = 1);
	void Move();

	UPROPERTY(BlueprintReadWrite) ASnake_Element *Snake_Element;
	UPROPERTY(EditDefaultsOnly) TSubclassOf<ASnake_Element> Snake_Element_Class;
	UPROPERTY() TArray<ASnake_Element*> Snake_Elements;
	UPROPERTY()EMovement_Direction Movement_Direction;

	UPROPERTY(EditDefaultsOnly) float Speed;
	UPROPERTY(EditDefaultsOnly) float Elements_Offset;

protected:
	virtual void BeginPlay();
};
//-------------------------------------------------------------------------------------------------------------
