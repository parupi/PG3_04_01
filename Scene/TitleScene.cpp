#include "TitleScene.h"


void TitleScene::Initialize()
{

}

void TitleScene::Update(char keys[256], char preKeys[256])
{
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw()
{
}
