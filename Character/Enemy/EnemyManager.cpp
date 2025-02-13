#include "EnemyManager.h"

void EnemyManager::Initialize()
{
	for (int i = 0; i < enemyNum; i++) {
		std::unique_ptr<Enemy> newEnemy = std::make_unique<Enemy>();
		newEnemy->Initialize();
		newEnemy->SetPosition({ 160.0f + (i * 320.0f), 32.0f });
		enemies_.push_back(std::move(newEnemy));
	}
}

void EnemyManager::Update()
{
	for (auto it = enemies_.begin(); it != enemies_.end();) {
		(*it)->Update();
		if (!(*it)->IsAlive()) {
			it = enemies_.erase(it);
		} else {
			++it;
		}
	}
}

void EnemyManager::Draw()
{
	for (const auto& enemy : enemies_) {
		enemy->Draw();
	}
}
