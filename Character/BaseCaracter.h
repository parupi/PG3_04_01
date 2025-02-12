#pragma once
#include <DirectXGame/math/Vector2.h>
class BaseCaracter
{
public:

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	Vector2 position_;
	Vector2 size_;
	Vector2 speed_;
	bool isAlive_;
};

