#include "Player_Pawn.h"

//-------------------------------------------------------------------------------------------------------------
APlayer_Pawn::APlayer_Pawn()
{
	PrimaryActorTick.bCanEverTick = true;
}
//-------------------------------------------------------------------------------------------------------------
void APlayer_Pawn::BeginPlay()
{
	Super::BeginPlay();
}
//-------------------------------------------------------------------------------------------------------------
void APlayer_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
//-------------------------------------------------------------------------------------------------------------
void APlayer_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
//-------------------------------------------------------------------------------------------------------------
