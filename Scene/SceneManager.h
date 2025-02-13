#pragma once

#include <memory>
#include "BaseScene.h"
#include "StageScene.h"
#include "TitleScene.h"
#include "ClearScene.h"

class SceneManager
{
public:
	SceneManager();



	// ゲームループを呼び出す
	int Run();
private:
	// シーンを保持する
	std::unique_ptr<BaseScene> sceneArr_[3];

	// どのステージを呼び出すかを管理する変数
	int currentSceneNo_;
	int preSceneNo_;

	// キー入力結果を受け取る箱
	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };
};

