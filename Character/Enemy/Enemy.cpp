#include "Enemy.h"
#include <Novice.h>

void Enemy::Initialize()
{
	size_ = { 32.0f, 32.0f };
	speed_ = { 0.0f, 0.0f };
}

void Enemy::Update()
{


}

void Enemy::Draw()
{
	Novice::DrawBox(int(position_.x - size_.x / 2.0f), int(position_.y - size_.y / 2.0f), int(size_.x), int(size_.y), 0.0f, 0xFF0000FF, kFillModeSolid);
}

void Enemy::OnCollision()
{
	isAlive = false;
}
