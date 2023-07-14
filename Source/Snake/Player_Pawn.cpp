#include "Player_Pawn.h"

//-------------------------------------------------------------------------------------------------------------
APlayer_Pawn::APlayer_Pawn()
{
	//PyrimarActorTick.bCanEverTick = true;
	Player_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player_Camera"));
	
	Player_Camera->SetWorldRotation(FRotator(-90, 0, 0));
	RootComponent = Player_Camera;
}
//-------------------------------------------------------------------------------------------------------------
void APlayer_Pawn::HandlePlayerVerticalInput(float value)
{
	if (IsValid(Snake))
	{
		if (value > 0 && Snake->Movement_Direction != EMovement_Direction::Down)
			Snake->Movement_Direction = EMovement_Direction::Up;
		else if (value < 0 && Snake->Movement_Direction != EMovement_Direction::Up)
			Snake->Movement_Direction = EMovement_Direction::Down;
	}
}
//-------------------------------------------------------------------------------------------------------------
void APlayer_Pawn::HandlePlayerHorizontalInput(float value)
{
	if (IsValid(Snake))
	{
		if (value > 0 && Snake->Movement_Direction != EMovement_Direction::Left)
			Snake->Movement_Direction = EMovement_Direction::Right;
		else if (value < 0 && Snake->Movement_Direction != EMovement_Direction::Right)
			Snake->Movement_Direction = EMovement_Direction::Left;
	}
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

	PlayerInputComponent->BindAxis("Horizontal", this, &APlayer_Pawn::HandlePlayerHorizontalInput);
	PlayerInputComponent->BindAxis("Vertical", this, &APlayer_Pawn::HandlePlayerVerticalInput);

}
//-------------------------------------------------------------------------------------------------------------
void APlayer_Pawn::Create_Snake()
{
	Snake = GetWorld()->SpawnActor<ASnakeBase>(Snake_Actor_Class, FTransform());
}
//-------------------------------------------------------------------------------------------------------------
void APlayer_Pawn::BeginPlay()
{
	Super::BeginPlay();
	Create_Snake();
}
//-------------------------------------------------------------------------------------------------------------
