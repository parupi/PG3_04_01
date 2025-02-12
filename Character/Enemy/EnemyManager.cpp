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
	for (const auto& enemy : enemies_) {
		enemy->Update();
	}
}

void EnemyManager::Draw()
{
	for (const auto& enemy : enemies_) {
		enemy->Draw();
	}
}
