#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SnakeBase.h"
#include "Player_Pawn.generated.h"

class UCameraComponent;

//-------------------------------------------------------------------------------------------------------------
UCLASS()
class SNAKE_API APlayer_Pawn : public APawn
{
	GENERATED_BODY()

public:
	APlayer_Pawn();

	virtual void Tick(float DeltaTime);
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

	void Create_Snake();

	UPROPERTY(BlueprintReadWrite) UCameraComponent *Player_Camera;
	UPROPERTY(BlueprintReadWrite) ASnakeBase *Snake;
	UPROPERTY(EditDefaultsOnly) TSubclassOf<ASnakeBase> Snake_Actor_Class;

protected:
	virtual void BeginPlay();
};
//-------------------------------------------------------------------------------------------------------------
