#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakeBase.generated.h"

//-------------------------------------------------------------------------------------------------------------
UCLASS()
class SNAKE_API ASnakeBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ASnakeBase();

	virtual void Tick(float DeltaTime);

protected:
	virtual void BeginPlay();
};
//-------------------------------------------------------------------------------------------------------------
