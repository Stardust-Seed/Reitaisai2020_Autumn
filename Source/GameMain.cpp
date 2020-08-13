#include <DxLib.h>
#include "GameMain.h"
#include "Input.h"

GameMain::GameMain() {

}

GameMain::~GameMain() {

}

void GameMain::Init() {

}

bool GameMain::GameLoop() {

	Input::Instance()->UpdateKey();

	sManager.Update();
	sManager.Draw();

	return true;
}