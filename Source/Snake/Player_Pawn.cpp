#include "Player_Pawn.h"
#include "Engine/Classes/Camera/CameraComponent.h"

//-------------------------------------------------------------------------------------------------------------
APlayer_Pawn::APlayer_Pawn()
{
	PrimaryActorTick.bCanEverTick = true;
	Player_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player_Camera"));
	
	Player_Camera->SetWorldRotation(FRotator(-90, 0, 0));
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
