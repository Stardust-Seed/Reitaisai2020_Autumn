#include <DxLib.h>
#include "LevelSelect.h"

LevelSelect::LevelSelect(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {
}

void LevelSelect::Update() {
	background.Update();

	if (CheckHitKey(KEY_INPUT_SPACE) == 1) {
		parameter->Set(BaseScene::LevelSelectTag, 2);

		sceneChanger->SceneChange(eScene_GAME, parameter, false, false);
	}
}

void LevelSelect::Draw() {
	background.Draw(eBackgroundType::Menu);
}