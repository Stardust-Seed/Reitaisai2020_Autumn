#include <DxLib.h>
#include "GameMain.h"

GameMain::GameMain() {
}

GameMain::~GameMain() {
}

void GameMain::Init() {
}

bool GameMain::GameLoop() {

	//ゲームの中身の処理を書く
	DrawString(0, 0, "Hello 河本大輝", GetColor(255, 255, 255));

	return true;
}