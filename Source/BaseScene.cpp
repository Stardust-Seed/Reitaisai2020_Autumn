#include "BaseScene.h"

const char* BaseScene::LevelSelectTag = "LevelSelect";
const char* BaseScene::CharaSelectTag = "CharaSelect";

/*�R���X�g���N�^*/
BaseScene::BaseScene(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:sceneChanger(_sceneChanger) {
	parameter = _parameter;
}

void BaseScene::Init() {
	parameter->Set(LevelSelectTag, 0);
	parameter->Set(CharaSelectTag, 0);
}