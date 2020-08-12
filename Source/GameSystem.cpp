#include <DxLib.h>
#include "GameSystem.h"

#include "Define.h"
#include "FPS.h"
#include "GameMain.h"

bool GameSystem::Init() {
	SetOutApplicationLogValidFlag(FALSE);					//���O�o�͂��s��Ȃ�
	ChangeWindowMode(TRUE);									//�E�B���h�E���[�h�ɕύX
	SetMainWindowText("�����͖{�^");						//�E�B���h�E�̃^�C�g����ύX����
	SetGraphMode(GAME_WIDTH, GAME_HEIHGT, GAME_COLORBIT);	//��ʂ̉𑜓x�ύX
	if (DxLib_Init()) {										//DX���C�u��������������
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);							//����ʏ�����ݒ肷��

	return true;
}

void GameSystem::Final() {
	DxLib_End();
}

void GameSystem::Main() {
	GameMain gMain;
	FPS fps;

	while (!ProcessMessage()) {
		ClearDrawScreen();

		if (!gMain.GameLoop())break;

		fps.Update();
		fps.Draw();

		ScreenFlip();
		fps.Wait();
	}
}