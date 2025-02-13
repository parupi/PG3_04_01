#pragma once
#include "Command/Command.h"
#include <memory>
#include <vector>
class InputHandler
{
public:
	std::vector<ICommand*> HandleInput();

	void AssignMoveRightCommand2PressKeyD();
	void AssignMoveLeftCommand2PressKeyA();
	void AssignShotBulletCommand2PressKeySpace();

private:
	std::unique_ptr<ICommand> pressKeyD_;
	std::unique_ptr<ICommand> pressKeyA_;
	std::unique_ptr<ICommand> pressKeySpace_;
};

