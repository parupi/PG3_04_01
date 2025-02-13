#include "ClearScene.h"

void ClearScene::Initialize()
{
}

void ClearScene::Update(char keys[256], char preKeys[256])
{
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) {
		sceneNo = TITLE;
	}
}

void ClearScene::Draw()
{
}
