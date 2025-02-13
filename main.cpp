#include <Novice.h>
#include <memory>
#include <Scene/SceneManager.h>

const char kWindowTitle[] = "LE2A_10_カワグチ_ハルキ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	std::unique_ptr<SceneManager> game = std::make_unique<SceneManager>();

	game->Run();

	return 0;
}
