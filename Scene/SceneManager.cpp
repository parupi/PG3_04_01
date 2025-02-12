#include "SceneManager.h"
#include <Novice.h>
SceneManager::SceneManager()
{
	// 各シーンを生成する
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	currentSceneNo_ = TITLE;
}

int SceneManager::Run()
{
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys_, keys_, 256);
		Novice::GetHitKeyStateAll(keys_);

		// シーンのチェック
		preSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		// シーンの変更チェック
		if (preSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Initialize();
		}

		// 更新
		sceneArr_[currentSceneNo_]->Update(preKeys_, keys_);
		sceneArr_[currentSceneNo_]->Draw();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys_[DIK_ESCAPE] == 0 && keys_[DIK_ESCAPE] != 0) {
			break;
		}

	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
