#pragma once
#include "BaseScene.h"
#include <memory>
#include <Character/Player/Player.h>
#include <Character/Enemy/EnemyManager.h>
#include <Command/InputHandler.h>
class StageScene : public BaseScene
{
public:
	void Initialize() override;
	void Update(char keys[256], char preKeys[256]) override;
	void Draw() override;
	void CheckCollision();
	void CheckIsClear();

private:
	std::unique_ptr<InputHandler> inputHandler_ = nullptr;
	//std::unique_ptr<ICommand> iCommand_ = nullptr;

	std::unique_ptr<Player> player_;
	std::unique_ptr<EnemyManager> enemyManager_;
};

