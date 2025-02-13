#pragma once
#include "Character/BaseCaracter.h"
class Enemy : public BaseCaracter
{
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void OnCollision();
private:
	bool isAlive = true;

public: // アクセッサ
	bool IsAlive() const { return isAlive; }
	Vector2 GetPosition() const { return position_; }
	Vector2 GetSize() const { return size_; }
	void SetPosition(Vector2 position) { position_ = position; }
	
};

