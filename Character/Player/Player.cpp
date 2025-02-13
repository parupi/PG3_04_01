#include "Player.h"
#include "Novice.h"

void Player::Initialize()
{
	position_ = { 640.0f, 540.0f };
	size_ = { 32.0f, 32.0f };
	speed_ = { 8.0f, 0.0f };
}

void Player::Update()
{
	for (auto it = bullets_.begin(); it != bullets_.end();) {
		(*it)->Update();
		if (!(*it)->IsAlive()) {
			it = bullets_.erase(it);
		} else {
			++it;
		}
	}
}

void Player::Draw()
{
	for (const auto& bullet : bullets_) {
		bullet->Draw();
	}

	Novice::DrawBox(int(position_.x - size_.x / 2.0f), int(position_.y - size_.y / 2.0f), int(size_.x), int(size_.y), 0.0f, 0xFFFFFFFF, kFillModeSolid);
}

void Player::MoveRight()
{
	position_.x += speed_.x;
}

void Player::MoveLeft()
{
	position_.x -= speed_.x;
}

void Player::ShotBullet()
{
	std::unique_ptr<Bullet> newBullet = std::make_unique<Bullet>();
	newBullet->Initialize(position_);
	bullets_.push_back(std::move(newBullet));
}
