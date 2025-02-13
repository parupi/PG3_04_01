#pragma once
#include "Character/BaseCaracter.h"
#include <memory>
#include "Bullet.h"
#include <list>
class Player : public BaseCaracter
{
public:
	void Initialize() override;
	void Update()override;
	void Draw() override;

	void MoveRight();
	void MoveLeft();
	void ShotBullet();

private:
	std::list<std::unique_ptr<Bullet>> bullets_;

public: // アクセッサ
	// bullets_ を const 参照で取得する
	const std::list<std::unique_ptr<Bullet>>& GetBullets() const { return bullets_; }
};