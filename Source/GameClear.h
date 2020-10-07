#ifndef _GAMECLEAR_H
#define _GAMECLEAR_H

#include "BaseScene.h"
#include "Input.h"
#include "Image.h"
#include "BGM.h"
#include "SE.h"
#include "Define.h"
#include "FontHandle.h"
#include "Cursor.h"

class GameClear final :public BaseScene {
private:
	const static int GAME_X;   //�u�Q�[���ɖ߂�v�e�L�X�g�\����X���W
	const static int TITLE_X;     //�u�^�C�g���ɖ߂�v�e�L�X�g�\����X���W
	const TCHAR* text1 = "�Q�[���N���A�I";
	const TCHAR* text2 = "������x����";
	const TCHAR* text3 = "���j���[�ɖ߂�";
	const TCHAR* text4 = "�\�Z�� ���";
	const TCHAR* text5 = "�Ђ�����f�o�b�O\n�Ђ�����f�o�b�O\n�Ђ�����f�o�b�O";
	const TCHAR* text6 = "�t�����h�[���E�X�J�[���b�g";
	const TCHAR* text7 = "�Ђ�����f�o�b�O\n�Ђ�����f�o�b�O\n�Ђ�����f�o�b�O";

	Cursor nowCursor;           //���ݑI�𒆂̃J�[�\��
	int x;                      //�J�[�\���\���p��X���W
	int alpha;                  //�����x
	int charaType;              //�L�����^�C�v
	int waitTimer;              //�V�[���؂�ւ��㏭���̊ԑ�����󂯕t���Ȃ��悤�ɂ���
public:
	GameClear(ISceneChanger* _sceneChanger, Parameter* _parameter);
	void Update();				//�X�V����
	void Draw();				//�`�揈��
	void Select();              //�I������
	void Move();                //�����̏���
};

#endif // !_GAMECLEAR_H