#include "InputHandler.h"
#include <Novice.h>

void InputHandler::AssignMoveRightCommand2PressKeyD()
{
    std::unique_ptr<ICommand> command = std::make_unique<MoveRightCommand>();
    pressKeyD_ = std::move(command);
}

void InputHandler::AssignMoveLeftCommand2PressKeyA()
{
    std::unique_ptr<ICommand> command = std::make_unique<MoveLeftCommand>();
    pressKeyA_ = std::move(command);
}

void InputHandler::AssignShotBulletCommand2PressKeySpace()
{
    std::unique_ptr<ICommand> command = std::make_unique<ShotSpaceCommand>();
    pressKeySpace_ = std::move(command);
}

std::vector<ICommand*> InputHandler::HandleInput()
{
    std::vector<ICommand*> commands; // 複数のコマンドを格納するベクター

    if (Novice::CheckHitKey(DIK_D) && pressKeyD_) {
        commands.push_back(pressKeyD_.get());
    }
    if (Novice::CheckHitKey(DIK_A) && pressKeyA_) {
        commands.push_back(pressKeyA_.get());
    }
    if (Novice::CheckHitKey(DIK_SPACE) && pressKeySpace_) {
        commands.push_back(pressKeySpace_.get());
    }

    return commands;
}