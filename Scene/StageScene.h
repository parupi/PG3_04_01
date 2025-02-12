#pragma once
#include "BaseScene.h"
#include <memory>
#include <Character/Player/Player.h>
#include <Character/Enemy/EnemyManager.h>
class StageScene : public BaseScene
{
public:
	void Initialize() override;
	void Update(char keys[256], char preKeys[256]) override;
	void Draw() override;

private:
	std::unique_ptr<Player> player_;
	std::unique_ptr<EnemyManager> enemyManager_;

};

