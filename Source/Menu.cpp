#include <DxLib.h>
#include "BGM.h"

#include "FontHandle.h"
#include "KuronekoLib.h"
#include "Image.h"
#include "Input.h"
#include "Menu.h"
#include "SE.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="_sceneChanger">�V�[���`�F���W���[</param>
/// <param name="_parameter">�p�����[�^</param>
Menu::Menu(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {
	//BGM���Đ�����
	BGM::Instance()->PlayBGM(BGM_menu, DX_PLAYTYPE_LOOP);

	//�����I�����v���C�ɐݒ�
	selectMenu = eMenuType::Game;

	//UI�t���[���̐F�������ݒ�
	cursor[static_cast<int>(eMenuType::Game)] = Cursor::Cursor_3;
	cursor[static_cast<int>(eMenuType::Option)] = Cursor::Cursor_0;
	cursor[static_cast<int>(eMenuType::Title)] = Cursor::Cursor_0;
	cursor[static_cast<int>(eMenuType::GameExit)] = Cursor::Cursor_0;

	//�t�F�[�h�J�E���g��������
	fadeCnt = 0;
}

/// <summary>
/// �X�V����
/// </summary>
void Menu::Update() {
	//���L�[�����͂��ꂽ�ꍇ
	if (Input::Instance()->GetPressCount(KEY_INPUT_DOWN) % 16 == 1 &&
		Input::Instance()->GetPressCount(KEY_INPUT_UP) == 0) {
		SelectMenu(CURSOR_DOWN);
	}

	//���L�[�����͂��ꂽ�ꍇ
	if (Input::Instance()->GetPressCount(KEY_INPUT_UP) % 16 == 1 &&
		Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 0) {
		SelectMenu(CURSOR_UP);
	}

	//z�L�[����͂��ꂽ�ꍇ
	if (Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1) {
		//SE��炷
		SE::Instance()->PlaySE(SE_cursor);

		//�V�[����؂�ւ���
		switch (selectMenu) {
		case eMenuType::Game:
			//�L�����I����ʂ�
			sceneChanger->SceneChange(eScene_CHARASELECT, parameter, true, false);
			break;
		case eMenuType::Option:
			//�I�v�V������ʂ�
			sceneChanger->SceneChange(eScene_OPTION, parameter, true, false);
			break;
		case eMenuType::Title:
			//BGM���~�߂�
			BGM::Instance()->StopBGM(BGM_menu);

			//�^�C�g����ʂ�
			sceneChanger->SceneChange(eScene_TITLE, parameter, false, false);
			break;
		case eMenuType::GameExit:
			//�Q�[�����I������
			exit(EXIT_SUCCESS);
			break;
		}
	}
}

/// <summary>
/// �`�揈��
/// </summary>
void Menu::Draw() {
/*------------------------------------------------------------------------------
UI�̕`��
------------------------------------------------------------------------------*/

	//�v���C
	DrawUIGraph(UI_X, UI_Y[static_cast<int>(eMenuType::Game)], UIFRAME_WIDTH, UIFRAME_HEIGHT,
		UI_EXT[0], UI_EXT[1], 0, UI_PAL, GetColor(255, 255, 255),
		static_cast<int>(cursor[static_cast<int>(eMenuType::Game)]), eDrawType::Center,
		FontHandle::Instance()->Get_natumemozi_100_3(), UI_FONTSIZE, "�v���C");

	//�I�v�V����
	DrawUIGraph(UI_X, UI_Y[static_cast<int>(eMenuType::Option)], UIFRAME_WIDTH, UIFRAME_HEIGHT,
		UI_EXT[0], UI_EXT[1], 0, UI_PAL, GetColor(255, 255, 255),
		static_cast<int>(cursor[static_cast<int>(eMenuType::Option)]), eDrawType::Center,
		FontHandle::Instance()->Get_natumemozi_100_3(), UI_FONTSIZE, "�I�v�V����");

	//�^�C�g���֖߂�
	DrawUIGraph(UI_X, UI_Y[static_cast<int>(eMenuType::Title)], UIFRAME_WIDTH, UIFRAME_HEIGHT,
		UI_EXT[0], UI_EXT[1], 0, UI_PAL, GetColor(255, 255, 255),
		static_cast<int>(cursor[static_cast<int>(eMenuType::Title)]), eDrawType::Center,
		FontHandle::Instance()->Get_natumemozi_100_3(), UI_FONTSIZE, "�^�C�g���֖߂�");

	//�Q�[���I��
	DrawUIGraph(UI_X, UI_Y[static_cast<int>(eMenuType::GameExit)], UIFRAME_WIDTH, UIFRAME_HEIGHT,
		UI_EXT[0], UI_EXT[1], 0, UI_PAL, GetColor(255, 255, 255),
		static_cast<int>(cursor[static_cast<int>(eMenuType::GameExit)]), eDrawType::Center,
		FontHandle::Instance()->Get_natumemozi_100_3(), UI_FONTSIZE, "�Q�[���I��");
}

/// <summary>
/// �I�����j���[��؂�ւ���
/// </summary>
/// <param name="_changeMode">�؂�ւ����[�h</param>
void Menu::SelectMenu(int _changeMode) {

	//SE��炷
	SE::Instance()->PlaySE(SE_cursor);

	//���ݑI������Ă鍀�ڂ̃J�[�\���t���[�����D�F��
	cursor[static_cast<int>(selectMenu)] = Cursor::Cursor_0;

	//�؂�ւ����[�h��DOWN�̏ꍇ
	if (_changeMode == CURSOR_DOWN) {
		//��ԉ��̍��ڂ̂Ƃ��A��ԏ�̍��ڂ�
		if (selectMenu == eMenuType::GameExit) {
			selectMenu = eMenuType::Game;
		}
		//��L�����O�̂Ƃ��A����̍��ڂ�
		else {
			selectMenu = static_cast<eMenuType>(static_cast<int>(selectMenu) + 1);
		}
	}
	//�؂�ւ����[�h��UP�̏ꍇ
	else if (_changeMode == CURSOR_UP) {
		//��ԏ�̍��ڂ̂Ƃ��A��ԉ��̍��ڂ�
		if (selectMenu == eMenuType::Game) {
			selectMenu = eMenuType::GameExit;
		}
		//��L�����O�̂Ƃ��A���̍��ڂ�
		else {
			selectMenu = static_cast<eMenuType>(static_cast<int>(selectMenu) - 1);
		}
	}

	//���ݑI������Ă鍀�ڂ̃J�[�\���t���[����F��
	cursor[static_cast<int>(selectMenu)] = Cursor::Cursor_3;
}