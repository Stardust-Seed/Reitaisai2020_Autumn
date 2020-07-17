#include <DxLib.h>
#include "GameSystem.h"

#include "GameMain.h"

bool GameSystem::Init() {
	SetOutApplicationLogValidFlag(FALSE);	//���O�o�͂��s��Ȃ�
	ChangeWindowMode(TRUE);					//�E�B���h�E���[�h�ɕύX
	SetMainWindowText("�����͖{�^");		//�E�B���h�E�̃^�C�g����ύX����
	SetGraphMode(1280, 720, 32);			//��ʂ̉𑜓x�ύX(�}�W�b�N�i���o�[�͌�ŏ���)
	if (DxLib_Init()) {						//DX���C�u��������������
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);			//����ʏ�����ݒ肷��

	return true;
}

void GameSystem::Final() {
	DxLib_End();
}

void GameSystem::Main() {
	GameMain gMain;

	gMain.Init();

	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
		if (!gMain.GameLoop()) {
			break;
		}
	}
}