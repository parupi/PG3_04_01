#pragma once
#include "BaseScene.h"
class ClearScene : public BaseScene
{
public:
	void Initialize() override;
	void Update(char keys[256], char preKeys[256]) override;
	void Draw() override;
};

