#include <DxLib.h>
#include "Input.h"
#include "LevelSelect.h"

LevelSelect::LevelSelect(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {
	selectLevel = eSelectLevel::Easy;
}

void LevelSelect::Update() {
	background.Update();

	//z�L�[�������ꂽ�Ƃ�
	if (Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1) {
		//�I�����ꂽ���x���ɏ]���ăp�����[�^�ɐ��l���Z�b�g
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

		//�V�[�����Q�[���V�[���ɐ؂�ւ���
		sceneChanger->SceneChange(eScene_GAME, parameter, false, false);
	}
}

void LevelSelect::Draw() {
	//background.Draw(eBackgroundType::Menu);
}