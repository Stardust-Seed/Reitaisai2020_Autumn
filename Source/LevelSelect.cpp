#include <DxLib.h>
#include "LevelSelect.h"

#include "Define.h"
#include "FontHandle.h"
#include "Image.h"
#include "Input.h"
#include "SE.h"

LevelSelect::LevelSelect(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {
	//����������
	selectLevel = eLevelType::Easy;

	//Easy�̏������W
	easyX = (GAME_WIDTH / 2);
	easyY = (GAME_HEIHGT / 2) - 300;

	//Normal�̏������W
	normalX = (GAME_WIDTH / 2);
	normalY = (GAME_HEIHGT / 2);

	//Hard�̏������W
	hardX = (GAME_WIDTH / 2);
	hardY = (GAME_HEIHGT / 2) + 300;

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
		ChangeLevel(CURSOR_DOWN);
	}

	/*------------------------------------------
	���L�[�������ꂽ�Ƃ�
	�����L�[�����͂���Ă���ꍇ�͏������s��Ȃ�
	------------------------------------------*/
	if (Input::Instance()->GetPressCount(KEY_INPUT_UP) % 16 == 1 &&
		Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 0) {
		ChangeLevel(CURSOR_UP);
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
	DrawUIBox(easyX, easyY, EASY, eLevelType::Easy, Cursor::Cursor_2);

	//Normal
	DrawUIBox(normalX, normalY, NORMAL, eLevelType::Normal, Cursor::Cursor_3);

	//Hard
	DrawUIBox(hardX, hardY, HARD, eLevelType::Hard, Cursor::Cursor_1);
}

void LevelSelect::ChangeLevel(int _changeMode) {
	//�t���O��؂�ւ���
	isChange = true;

	//SE��炷
	SE::Instance()->PlaySE(SE_cursor);

	//�I�����ꂽ���x����Ԃ�
	switch (selectLevel) {
	case eLevelType::Easy:
		//�J�[�\��UP�̂Ƃ�
		if (_changeMode == CURSOR_UP) {
			selectLevel = eLevelType::Hard;
		}
		//�J�[�\��DOWN�̂Ƃ�
		else if (_changeMode == CURSOR_DOWN) {
			selectLevel = eLevelType::Normal;
		}
		break;
	case eLevelType::Normal:
		//�J�[�\��UP�̂Ƃ�
		if (_changeMode == CURSOR_UP) {
			selectLevel = eLevelType::Easy;
		}
		//�J�[�\��DOWN�̂Ƃ�
		else if (_changeMode == CURSOR_DOWN) {
			selectLevel = eLevelType::Hard;
		}
		break;
	case eLevelType::Hard:
		//�J�[�\��UP�̂Ƃ�
		if (_changeMode == CURSOR_UP) {
			selectLevel = eLevelType::Normal;
		}
		//�J�[�\��DOWN�̂Ƃ�
		else if (_changeMode == CURSOR_DOWN) {
			selectLevel = eLevelType::Easy;
		}
		break;
	}
}

//UI�̕`�揈��
void LevelSelect::DrawUIBox(float _x, float _y, string _text,
	eLevelType _levelType, Cursor _cursor) {

	int textSize = _text.size();

	//�I������Ă��Ȃ����x����������D�F�ɂ���
	if (selectLevel != _levelType) {
		_cursor = Cursor::Cursor_0;
	}

	//�u�����h���[�h���A���t�@�u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);

	//�l�p�`�̕`��
	DrawRotaGraph3F(_x, _y, 650 / 2, 250 / 2, 1.0, 1.0, (0 * PAI) / 180,
		Image::Instance()->GetGraph(eImageType::UI_CursorFrame, static_cast<int>(_cursor)),
		FALSE);

	//�����̕`��
	DrawStringToHandle(_x - ((100 / 2) * (textSize / 2)), _y - (100 / 2),
		_text.c_str(), GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_100_3());

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