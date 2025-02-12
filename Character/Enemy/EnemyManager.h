#pragma once
#include <list>
#include "Enemy.h"
#include <memory>
class EnemyManager
{
public:
	void Initialize();
	void Update();
	void Draw();
private:
	std::list<std::unique_ptr<Enemy>> enemies_;

	const int enemyNum = 4;
};

