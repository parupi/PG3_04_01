#include "StageScene.h"

void StageScene::Initialize()
{
	player_ = std::make_unique<Player>();
	player_->Initialize();

	enemyManager_ = std::make_unique<EnemyManager>();
	enemyManager_->Initialize();
}

void StageScene::Update(char keys[256], char preKeys[256])
{
	player_->Update(keys, preKeys);
	enemyManager_->Update();

	CheckCollision();
	CheckIsClear();
}

void StageScene::Draw()
{
	player_->Draw();
	enemyManager_->Draw();
}

void StageScene::CheckCollision()
{
	const auto& bullets = player_->GetBullets();
	const auto& enemies = enemyManager_->GetEnemies();

	for (const auto& enemy : enemies) {
		for (const auto& bullet : bullets) {
			Vector2 diff = enemy->GetPosition() - bullet->GetPosition();

			// X, Y の距離が負の場合に対応
			float absX = std::abs(diff.x);
			float absY = std::abs(diff.y);

			// 当たり判定の閾値
			float thresholdX = (enemy->GetSize().x + bullet->GetSize().x) * 0.5f;
			float thresholdY = (enemy->GetSize().y + bullet->GetSize().y) * 0.5f;

			// 判定修正
			if (absX <= thresholdX && absY <= thresholdY) {
				enemy->OnCollision();
				bullet->OnCollision();
			}

		}
	}
}

void StageScene::CheckIsClear()
{
	if (enemyManager_->GetEnemies().size() <= 0) {
		sceneNo = CLEAR;
	}
}
