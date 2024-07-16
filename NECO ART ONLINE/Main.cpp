#include "DxLib.h"
#include "Scene/Scene.h"
#include "Scene/SceneManager.h"
#include "Scene/GameScene.h"
#include "Game.h"
#include "Input.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 一部の関数はDxLib_Init()の前に実行する必要がある
	// 一部の関数はDxLib_Init()の前に実行する必要がある
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, 16);
	ChangeWindowMode(true);


	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//3D描画の奥行情報を使用する設定
	SetUseZBuffer3D(true);
	//描画を行うとき、Zバッファにも書き込むようにする
	SetWriteZBuffer3D(true);

	SceneManager manager;
	manager.ChangeScene(std::make_shared<GameScene>(manager));
	Input input;
	manager.Init();


	//ゲームループ
	while (ProcessMessage() != -1)
	{
		//このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする
		ClearDrawScreen();
		
		input.Update();
		manager.Init();
		manager.Update(input);
		manager.Draw();

		// 画面が切り替わるのを待つ
		ScreenFlip();

		//escキーでゲーム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//FPS60固定にする
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			//16.66ミリ秒(16667マイクロ秒)経過するまで待つ
		}
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}