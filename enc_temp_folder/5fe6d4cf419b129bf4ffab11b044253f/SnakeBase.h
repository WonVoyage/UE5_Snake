#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Snake_Element.h"
#include "SnakeBase.generated.h"

//-------------------------------------------------------------------------------------------------------------
UCLASS()
class SNAKE_API ASnakeBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ASnakeBase();

	virtual void Tick(float DeltaTime);

	UPROPERTY(BlueprintReadWrite) ASnake_Element *Snake_Element;
	TSubclassOf<ASnake_Element> Snake_Element_Class;


protected:
	virtual void BeginPlay();
};
//-------------------------------------------------------------------------------------------------------------
