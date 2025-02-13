#include "Command.h"
#include "Character/Player/Player.h"

ICommand::~ICommand(){}

void MoveRightCommand::Exec(Player& player)
{
	player.MoveRight();
}

void MoveLeftCommand::Exec(Player& player)
{
	player.MoveLeft();
}

void ShotSpaceCommand::Exec(Player& player)
{
	player.ShotBullet();
}
