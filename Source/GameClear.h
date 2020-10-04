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

	Cursor nowCursor;           //���ݑI�𒆂̃J�[�\��
	int x;                      //�J�[�\���\���p��X���W
	int alpha;                  //�����x
	int charaType;              //�L�����^�C�v
public:
	GameClear(ISceneChanger* _sceneChanger, Parameter* _parameter);
	void Update();				//�X�V����
	void Draw();				//�`�揈��
	void Select();              //�I������
	void Move();                //�����̏���
};

#endif // !_GAMECLEAR_H