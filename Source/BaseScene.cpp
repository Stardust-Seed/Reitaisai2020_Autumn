#include "BaseScene.h"

const string BaseScene::LevelSelectTag = "LevelSelect";
const string BaseScene::CharaSelectTag = "CharaSelect";

/*�R���X�g���N�^*/
BaseScene::BaseScene(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:sceneChanger(_sceneChanger) {
	parameter = _parameter;
}

void BaseScene::Init() {
	parameter->Set(LevelSelectTag, 0);
	parameter->Set(CharaSelectTag, 0);
}