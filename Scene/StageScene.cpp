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
}

void StageScene::Draw()
{
	player_->Draw();
	enemyManager_->Draw();
}
