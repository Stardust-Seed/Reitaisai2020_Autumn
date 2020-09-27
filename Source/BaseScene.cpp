#include "BaseScene.h"

const char* BaseScene::LevelSelectTag = "LevelSelect";
const char* BaseScene::CharaSelectTag = "CharaSelect";

/*コンストラクタ*/
BaseScene::BaseScene(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:sceneChanger(_sceneChanger) {
	parameter = _parameter;
}