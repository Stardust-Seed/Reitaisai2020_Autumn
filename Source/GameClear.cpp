#include <DxLib.h>
#include "GameClear.h"
#include "Input.h"

GameClear::GameClear(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {
}

/*更新処理*/
void GameClear::Update() {
	if (Input::Instance()->GetPressCount(KEY_INPUT_SPACE) == 1) {
		sceneChanger->SceneChange(eScene_MENU, parameter, false, false);
	}
}

/*描画処理*/
void GameClear::Draw() {
	DrawBoxAA(50, 50, 874, 250, GetColor(255, 255, 255), TRUE);
	DrawString(412-(13*7), 150+7, "Clearしたね！！おめでとう", GetColor(0, 0, 0));

	DrawBoxAA(619, 263, 1019, 763, GetColor(255, 255, 255), TRUE);
	DrawString(200, 568, "Press the space key to return menu", GetColor(255, 255, 255));
}