#pragma once
#include <DirectXGame/math/Vector2.h>
class Bullet
{
public:
	void Initialize(Vector2 position);
	void Update();
	void Draw();

public: // アクセッサ
	bool IsAlive() const { return isAlive; }
	Vector2 GetPosition() const { return position_; }
	Vector2 GetSize() const { return size_; }

	void OnCollision();

private:
	Vector2 position_;
	Vector2 size_;
	Vector2 speed_;
	bool isAlive;
};

