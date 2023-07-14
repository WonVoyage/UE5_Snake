#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Player_Pawn.generated.h"

//-------------------------------------------------------------------------------------------------------------
UCLASS() class SNAKE_API APlayer_Pawn : public APawn
{
	GENERATED_BODY()

public:
	APlayer_Pawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
//-------------------------------------------------------------------------------------------------------------
