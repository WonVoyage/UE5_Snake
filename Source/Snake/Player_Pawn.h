#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Player_Pawn.generated.h"

class UCameraComponent;

//-------------------------------------------------------------------------------------------------------------
UCLASS() class SNAKE_API APlayer_Pawn : public APawn
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite) UCameraComponent *Player_Camera;

	APlayer_Pawn();

protected:
	virtual void BeginPlay() override;
};
//-------------------------------------------------------------------------------------------------------------
