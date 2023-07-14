#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "Snake_Element.generated.h"

//-------------------------------------------------------------------------------------------------------------
UCLASS()
class SNAKE_API ASnake_Element : public AActor
{
	GENERATED_BODY()
	
public:	
	ASnake_Element();

	virtual void Tick(float DeltaTime);

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly) UStaticMeshComponent *Snake_Element_Mesh;

protected:
	virtual void BeginPlay();
};
//-------------------------------------------------------------------------------------------------------------
