#pragma once
#include <dinput.h>
// シーン名を定義
enum SCENE {
	TITLE,
	STAGE,
	CLEAR
};

class BaseScene
{
protected:
	// シーン番号を管理する変数
	static int sceneNo;

	// キー入力結果を受け取る箱
	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };

public:
	virtual void Initialize() = 0;
	virtual void Update(char keys[256], char preKeys[256]) = 0;
	virtual void Draw() = 0;

	virtual ~BaseScene();

	// シーンの番号を取得
	int GetSceneNo() { return sceneNo; };
};

