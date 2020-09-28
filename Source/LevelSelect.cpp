#include <DxLib.h>
#include "Input.h"
#include "LevelSelect.h"

LevelSelect::LevelSelect(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {
	selectLevel = eSelectLevel::Easy;
}

void LevelSelect::Update() {
	background.Update();

	//zキーが押されたとき
	if (Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1) {
		//選択されたレベルに従ってパラメータに数値をセット
		switch (selectLevel) {
		case eSelectLevel::Easy:
			parameter->Set(BaseScene::LevelSelectTag, 0);
			break;
		case eSelectLevel::Normal:
			parameter->Set(BaseScene::LevelSelectTag, 1);
			break;
		case eSelectLevel::Hard:
			parameter->Set(BaseScene::LevelSelectTag, 2);
			break;
		}

		//シーンをゲームシーンに切り替える
		sceneChanger->SceneChange(eScene_GAME, parameter, false, false);
	}
}

void LevelSelect::Draw() {
	//background.Draw(eBackgroundType::Menu);
}