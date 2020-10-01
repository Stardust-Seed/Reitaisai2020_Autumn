#include <DxLib.h>
#include "LevelSelect.h"

#include "BGM.h"
#include "FontHandle.h"
#include "KuronekoLib.h"
#include "Image.h"
#include "Input.h"
#include "SE.h"

LevelSelect::LevelSelect(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {
	//����������
	selectLevel = eLevelType::Easy;

	//UI�t���[���̐F�������ݒ�
	cursor[static_cast<int>(eLevelType::Easy)] = Cursor::Cursor_2;
	cursor[static_cast<int>(eLevelType::Normal)] = Cursor::Cursor_0;
	cursor[static_cast<int>(eLevelType::Hard)] = Cursor::Cursor_0;

	//�؂�ւ���t���O��������
	isChange = false;
}

void LevelSelect::Update() {

	//�I�����ꂽ���ڂɐF��t���āA����ȊO�͊D�F�ɐݒ肷��
	if (isChange == true) {
		switch (selectLevel) {
		case eLevelType::Easy:
			cursor[static_cast<int>(eLevelType::Easy)] = Cursor::Cursor_2;
			cursor[static_cast<int>(eLevelType::Normal)] = Cursor::Cursor_0;
			cursor[static_cast<int>(eLevelType::Hard)] = Cursor::Cursor_0;
			break;
		case eLevelType::Normal:
			cursor[static_cast<int>(eLevelType::Easy)] = Cursor::Cursor_0;
			cursor[static_cast<int>(eLevelType::Normal)] = Cursor::Cursor_3;
			cursor[static_cast<int>(eLevelType::Hard)] = Cursor::Cursor_0;
			break;
		case eLevelType::Hard:
			cursor[static_cast<int>(eLevelType::Easy)] = Cursor::Cursor_0;
			cursor[static_cast<int>(eLevelType::Normal)] = Cursor::Cursor_0;
			cursor[static_cast<int>(eLevelType::Hard)] = Cursor::Cursor_1;
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
		sceneChanger->SceneChange(eScene_CHARASELECT, parameter, true, false);
	}
}

//�`�揈��
void LevelSelect::Draw() {
/*------------------------------------------------------------------------------
�w�i�̕`��
------------------------------------------------------------------------------*/
	DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Title), TRUE);
	DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Filter), TRUE);
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