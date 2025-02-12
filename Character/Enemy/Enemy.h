#pragma once
#include "Character/BaseCaracter.h"
class Enemy : public BaseCaracter
{
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;

	void SetPosition(Vector2 position) { position_ = position; }
};

