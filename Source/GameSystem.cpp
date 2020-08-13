#include <DxLib.h>
#include "GameSystem.h"

#include "Define.h"
#include "FPS.h"
#include "GameMain.h"

bool GameSystem::Init() {
	SetOutApplicationLogValidFlag(FALSE);					//ログ出力を行わない
	ChangeWindowMode(TRUE);									//ウィンドウモードに変更
	SetMainWindowText("東方河本録");						//ウィンドウのタイトルを変更する
	SetGraphMode(GAME_WIDTH, GAME_HEIHGT, GAME_COLORBIT);	//画面の解像度変更
	if (DxLib_Init()) {										//DXライブラリ初期化処理
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);							//裏画面処理を設定する

	return true;
}

void GameSystem::Final() {
	DxLib_End();
}

void GameSystem::Main() {
	GameMain gMain;
	FPS fps;

	while (!ProcessMessage()) {
		ClearDrawScreen();

		if (!gMain.GameLoop())break;

		fps.Update();
		fps.Draw();

		ScreenFlip();
		fps.Wait();
	}
}