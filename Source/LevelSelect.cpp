#include <DxLib.h>
#include "LevelSelect.h"

#include "Define.h"
#include "FontHandle.h"
#include "Input.h"
#include "SE.h"

LevelSelect::LevelSelect(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {
	//����������
	selectLevel = eLevelType::Easy;

	//Easy�̏������W
	easyX1 = (GAME_WIDTH / 2) - 300;
	easyX2 = (GAME_WIDTH / 2) + 300;
	easyY1 = (GAME_HEIHGT / 2) - 400;
	easyY2 = (GAME_HEIHGT / 2) - 200;

	//Normal�̏������W
	normalX1 = (GAME_WIDTH / 2) - 300;
	normalX2 = (GAME_WIDTH / 2) + 300;
	normalY1 = (GAME_HEIHGT / 2) - 100;
	normalY2 = (GAME_HEIHGT / 2) + 100;

	//Hard�̏������W
	hardX1 = (GAME_WIDTH / 2) - 300;
	hardX2 = (GAME_WIDTH / 2) + 300;
	hardY1 = (GAME_HEIHGT / 2) + 200;
	hardY2 = (GAME_HEIHGT / 2) + 400;

	//�A�j���[�V�����J�E���g�̏�����
	animationCnt = 0;

	//�؂�ւ��t���O�̏�����
	isChange = false;
}

void LevelSelect::Update() {
	/*------------------------------------------
	���L�[�������ꂽ�Ƃ�
	�����L�[�����͂���Ă���ꍇ�͏������s��Ȃ�
	------------------------------------------*/
	if (Input::Instance()->GetPressCount(KEY_INPUT_DOWN) % 16 == 1 &&
		Input::Instance()->GetPressCount(KEY_INPUT_UP) == 0) {
		/*--------------------------------------
		���ݑI�𒆂̃��x���̉��̍��ڂɐ؂�ւ���
		��Hard�̏ꍇ��ԏ��Easy�Ɉړ�����
		--------------------------------------*/
		switch (selectLevel) {
		case eLevelType::Easy:
			selectLevel = eLevelType::Normal;
			break;
		case eLevelType::Normal:
			selectLevel = eLevelType::Hard;
			break;
		case eLevelType::Hard:
			selectLevel = eLevelType::Easy;
			break;
		}

		//�t���O��؂�ւ���
		isChange = true;

		//SE��炷
		SE::Instance()->PlaySE(SE_cursor);
	}

	/*------------------------------------------
	���L�[�������ꂽ�Ƃ�
	�����L�[�����͂���Ă���ꍇ�͏������s��Ȃ�
	------------------------------------------*/
	if (Input::Instance()->GetPressCount(KEY_INPUT_UP) % 16 == 1 &&
		Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 0) {
		/*--------------------------------------
		���ݑI�𒆂̃��x���̏�̍��ڂɐ؂�ւ���
		��Easy�̏ꍇ��ԉ���Hard�Ɉړ�����
		--------------------------------------*/
		switch (selectLevel) {
		case eLevelType::Easy:
			selectLevel = eLevelType::Hard;
			break;
		case eLevelType::Normal:
			selectLevel = eLevelType::Easy;
			break;
		case eLevelType::Hard:
			selectLevel = eLevelType::Normal;
			break;
		}

		//�t���O��؂�ւ���
		isChange = true;

		//SE��炷
		SE::Instance()->PlaySE(SE_cursor);
	}

	//z�L�[�������ꂽ�Ƃ�
	if (Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1) {
		//�I�����ꂽ���x���ɏ]���ăp�����[�^�ɐ��l���Z�b�g
		switch (selectLevel) {
		case eLevelType::Easy:
			parameter->Set(BaseScene::LevelSelectTag, 0);
			break;
		case eLevelType::Normal:
			parameter->Set(BaseScene::LevelSelectTag, 1);
			break;
		case eLevelType::Hard:
			parameter->Set(BaseScene::LevelSelectTag, 2);
			break;
		}

		//�V�[�����Q�[���V�[���ɐ؂�ւ���
		sceneChanger->SceneChange(eScene_GAME, parameter, false, false);
	}

	//�؂�ւ��̃A�j���[�V��������
	if (isChange == true) {
		Animation();
	}
}

//�`�揈��
void LevelSelect::Draw() {
	/*-----------------------------------------------------------------------
	UI�̕`��
	-----------------------------------------------------------------------*/
	//Easy
	DrawUIBox(easyX1, easyY1, easyX2, easyY2, GetColor(0, 255, 0),
		"Easy", eLevelType::Easy);

	//Normal
	DrawUIBox(normalX1, normalY1, normalX2, normalY2, GetColor(0, 0, 255),
		"Normal", eLevelType::Normal);

	//Hard
	DrawUIBox(hardX1, hardY1, hardX2, hardY2, GetColor(255, 0, 0),
		"Hard", eLevelType::Hard);
}

void LevelSelect::ChangeLevel() {

}

//UI�̕`�揈��
void LevelSelect::DrawUIBox(float _x1, float _y1, float _x2, float _y2, unsigned int _color,
	const char* _text, eLevelType _levelType) {

	//�I������Ă��Ȃ����x����������D�F�ɂ���
	if (selectLevel != _levelType) {
		_color = GetColor(125, 125, 125);
	}

	//�u�����h���[�h���A���t�@�u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);

	//�l�p�`�̕`��
	DrawBoxAA(_x1, _y1, _x2, _y2, _color, TRUE);

	//�����̕`��
	DrawStringToHandle(_x1, _y1, _text, GetColor(255, 255, 255),
		FontHandle::Instance()->Get_natumemozi_100_3());

	//�u�����h���[�h���m�[�u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//�؂�ւ��A�j���[�V�����̏���
void LevelSelect::Animation() {
	if (animationCnt >= 16) {
		animationCnt = 0;
		isChange = false;
	}

	animationCnt++;
}