#include "Player.h"
#include "Novice.h"

void Player::Initialize()
{
	position_ = { 640.0f, 540.0f };
	size_ = { 32.0f, 32.0f };
	speed_ = { 8.0f, 0.0f };
}

void Player::Update(char keys[256], char preKeys[256])
{
	if (keys[DIK_A]) {
		position_.x -= speed_.x;
	}
	if (keys[DIK_D]) {
		position_.x += speed_.x;
	}

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		std::unique_ptr<Bullet> newBullet = std::make_unique<Bullet>();
		newBullet->Initialize(position_);
		bullets_.push_back(std::move(newBullet));
	}

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
