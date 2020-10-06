#include <DxLib.h>
#include "LevelSelect.h"

#include "BGM.h"
#include "FontHandle.h"
#include "KuronekoLib.h"
#include "Image.h"
#include "Input.h"
#include "SE.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="_sceneChanger">�V�[���؂�ւ��N���X</param>
/// <param name="_parameter">�p�����[�^</param>
LevelSelect::LevelSelect(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {
	//����������
	selectLevel = eLevelType::Easy;

	//UI�t���[���̐F�������ݒ�
	SetCursor(Cursor::Cursor_2, Cursor::Cursor_0, Cursor::Cursor_0);

	//�؂�ւ���t���O��������
	isChange = false;
}

/// <summary>
/// �X�V����
/// </summary>
void LevelSelect::Update() {

	//�I�����ꂽ���ڂɐF��t���āA����ȊO�͊D�F�ɐݒ肷��
	if (isChange == true) {
		switch (selectLevel) {
		case eLevelType::Easy:
			SetCursor(Cursor::Cursor_2, Cursor::Cursor_0, Cursor::Cursor_0);
			break;
		case eLevelType::Normal:
			SetCursor(Cursor::Cursor_0, Cursor::Cursor_3, Cursor::Cursor_0);
			break;
		case eLevelType::Hard:
			SetCursor(Cursor::Cursor_0, Cursor::Cursor_0, Cursor::Cursor_1);
			break;
		}

		//�؂�ւ��t���O��false�ɂ���
		isChange = false;
	}

	//���L�[�������ꂽ�Ƃ�
	if (Input::Instance()->GetPressCount(KEY_INPUT_DOWN) % 16 == 1 &&
		Input::Instance()->GetPressCount(KEY_INPUT_UP) == 0) {
		ChangeLevel(CURSOR_DOWN);
	}

	//���L�[�������ꂽ�Ƃ�
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

		//���j���[��BGM���~�߂�
		BGM::Instance()->StopBGM(BGM_menu);

		//�V�[�����Q�[���V�[���ɐ؂�ւ���
		sceneChanger->SceneChange(eScene_GAME, parameter, false, false);
	}

	//x�L�[�������ꂽ�Ƃ�
	if (Input::Instance()->GetPressCount(KEY_INPUT_X) == 1) {
		sceneChanger->SceneChange(eScene_CHARASELECT, parameter, false, true);
	}
}

/// <summary>
/// �`�揈��
/// </summary>
void LevelSelect::Draw() {
/*------------------------------------------------------------------------------
UI�̕`��
------------------------------------------------------------------------------*/
	//Easy
	DrawUIGraph(UI_X, UI_Y[static_cast<int>(eLevelType::Easy)], UIFRAME_WIDTH, UIFRAME_HEIGHT,
		UI_EXT, UI_EXT, 0, UI_PAL, GetColor(255, 255, 255),
		static_cast<int>(cursor[static_cast<int>(eLevelType::Easy)]), eDrawType::Center,
		FontHandle::Instance()->Get_natumemozi_100_3(), UI_FONTSIZE, "Easy");

	//Normal
	DrawUIGraph(UI_X, UI_Y[static_cast<int>(eLevelType::Normal)], UIFRAME_WIDTH, UIFRAME_HEIGHT,
		UI_EXT, UI_EXT, 0, UI_PAL, GetColor(255, 255, 255),
		static_cast<int>(cursor[static_cast<int>(eLevelType::Normal)]), eDrawType::Center,
		FontHandle::Instance()->Get_natumemozi_100_3(), UI_FONTSIZE, "Normal");

	//Hard
	DrawUIGraph(UI_X, UI_Y[static_cast<int>(eLevelType::Hard)], UIFRAME_WIDTH, UIFRAME_HEIGHT,
		UI_EXT, UI_EXT, 0, UI_PAL, GetColor(255, 255, 255),
		static_cast<int>(cursor[static_cast<int>(eLevelType::Hard)]), eDrawType::Center,
		FontHandle::Instance()->Get_natumemozi_100_3(), UI_FONTSIZE, "Hard");
}

/// <summary>
/// �I�����x����؂�ւ���
/// </summary>
/// <param name="_changeMode">�؂�ւ����[�h</param>
void LevelSelect::ChangeLevel(int _changeMode) {
	//SE��炷
	SE::Instance()->PlaySE(SE_cursor);

	//�؂�ւ��t���O��true�ɂ���
	isChange = true;

	//�؂�ւ����[�h��DOWN�̏ꍇ
	if (_changeMode == CURSOR_DOWN) {
		//��ԉ��̍��ڂ̂Ƃ��A��ԏ�̍��ڂ�
		if (selectLevel == eLevelType::Hard) {
			selectLevel = eLevelType::Easy;
		}
		//��L�����O�̂Ƃ��A����̍��ڂ�
		else {
			selectLevel = static_cast<eLevelType>(static_cast<int>(selectLevel) + 1);
		}
	}
	//�؂�ւ����[�h��UP�̏ꍇ
	else if (_changeMode == CURSOR_UP) {
		//��ԏ�̍��ڂ̂Ƃ��A��ԉ��̍��ڂ�
		if (selectLevel == eLevelType::Easy) {
			selectLevel = eLevelType::Hard;
		}
		//��L�����O�̂Ƃ��A���̍��ڂ�
		else {
			selectLevel = static_cast<eLevelType>(static_cast<int>(selectLevel) - 1);
		}
	}
}

/// <summary>
/// �����̃J�[�\�����e�J�[�\���ɃZ�b�g����
/// </summary>
/// <param name="_easy">Easy�̃J�[�\��</param>
/// <param name="_normal">Normal�̃J�[�\��</param>
/// <param name="_hard">Hard�̃J�[�\��</param>
void LevelSelect::SetCursor(Cursor _easy, Cursor _normal, Cursor _hard) {
	//Easy�̃J�[�\�����Z�b�g����
	cursor[static_cast<int>(eLevelType::Easy)] = _easy;

	//Normal�̃J�[�\�����Z�b�g����
	cursor[static_cast<int>(eLevelType::Normal)] = _normal;

	//Hard�̃J�[�\�����Z�b�g����
	cursor[static_cast<int>(eLevelType::Hard)] = _hard;
}

/// <summary>
/// �N���A�t���O���Z�b�g����
/// </summary>
/// <param name="_buf">�o�b�t�@</param>
/// <param name="_level">���x��</param>
void LevelSelect::SetIsClear(int _buf, eLevelType _level) {
	//�o�b�t�@��0�̎�false�A1�̎�true���Z�b�g
	if (_buf == 0) {
		isClear[static_cast<int>(_level)] = false;
	}
	else {
		isClear[static_cast<int>(_level)] = true;
	}
}