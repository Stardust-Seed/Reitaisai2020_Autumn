#include <DxLib.h>
#include "GameMain.h"

GameMain::GameMain() {
}

GameMain::~GameMain() {
}

void GameMain::Init() {
}

bool GameMain::GameLoop() {

	//�Q�[���̒��g�̏���������
	DrawString(0, 0, "Hello �͖{��P", GetColor(255, 255, 255));

	return true;
}