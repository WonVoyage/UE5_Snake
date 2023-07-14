#include "Player_Pawn.h"
#include "Engine/Classes/Camera/CameraComponent.h"

//-------------------------------------------------------------------------------------------------------------
APlayer_Pawn::APlayer_Pawn()
{
	//PyrimarActorTick.bCanEverTick = true;
	Player_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player_Camera"));
	
	Player_Camera->SetWorldRotation(FRotator(-90, 0, 0));
	RootComponent = Player_Camera;
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
