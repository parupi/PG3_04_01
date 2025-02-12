#include "Bullet.h"
#include <Novice.h>

void Bullet::Initialize(Vector2 position)
{
	position_ = position;
	size_ = { 16.0f, 16.0f };
	speed_ = { 0.0f, -12.0f };
	isAlive = true;
}

void Bullet::Update()
{
	position_.y += speed_.y;

	if (position_.y <= -size_.y) {
		isAlive = false;
	}
}

void Bullet::Draw()
{
	Novice::DrawBox(int(position_.x - size_.x / 2.0f), int(position_.y - size_.y / 2.0f), int(size_.x), int(size_.y), 0.0f, 0xFFFFFFFF, kFillModeSolid);
}
