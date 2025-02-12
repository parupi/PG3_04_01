#pragma once
#include <DirectXGame/math/Vector2.h>
class Bullet
{
public:
	void Initialize(Vector2 position);
	void Update();
	void Draw();

public:
	bool IsAlive() const { return isAlive; }

private:
	Vector2 position_;
	Vector2 size_;
	Vector2 speed_;
	bool isAlive;
};

