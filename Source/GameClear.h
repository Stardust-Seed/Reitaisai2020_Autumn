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
#include "File.h"

class GameClear final :public BaseScene {
private:
	const static int GAME_X;   //�u�Q�[���ɖ߂�v�e�L�X�g�\����X���W
	const static int TITLE_X;     //�u�^�C�g���ɖ߂�v�e�L�X�g�\����X���W
	const TCHAR* text1 = "�Q�[���N���A�I";
	const TCHAR* text2 = "������x����";
	const TCHAR* text3 = "���j���[�ɖ߂�";
	const TCHAR* text4 = "�\�Z�� ���";
	const TCHAR* text5 = "�t�t�b �g���ق̃��C�h���Ƃ��ē��R�̂��Ƃ���";
	const TCHAR* text6 = "�t�����h�[���ES";
	const TCHAR* text7 = "�t�t�t�b ���o���܂ɖJ�߂Ă��炤�񂾁`";

	Cursor nowCursor;           //���ݑI�𒆂̃J�[�\��
	int x;                      //�J�[�\���\���p��X���W
	int alpha;                  //�����x
	int charaType;              //�L�����^�C�v
	int waitTimer;              //�V�[���؂�ւ��㏭���̊ԑ�����󂯕t���Ȃ��悤�ɂ���
public:
	GameClear(ISceneChanger* _sceneChanger, Parameter* _parameter);
	void Update(GameResource* _gameRes);				//�X�V����
	void Draw(GameResource* _gameRes);				//�`�揈��
	void Select();              //�I������
	void Move();                //�����̏���
};

#endif // !_GAMECLEAR_H