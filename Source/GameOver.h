#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_

#include "BaseScene.h"
#include "Input.h"
#include "Image.h"
#include "BGM.h"
#include "SE.h"
#include "Define.h"
#include "FontHandle.h"

enum Continuity                 //�I��������̂Ɏg���܂�
{
	//��X�A���ڂ������Ă������悤��min,max�̍��ڂ�ݒ肵�Ă���
	Continuity_Min,             //�Œ�l
	Continuity_Yes,             //�R���e�B�j���[����
    Continuity_No,              //�R���e�B�j���[���Ȃ�
	Continuity_Max              //�ő�l
};

class GameOver :public virtual BaseScene{

private:
	const static int GAME_X = GAME_WIDTH / 7.5f - 45;    //�R���e�B�j���[����ƕ\������e�L�X�g��Y���W
	const static int MENU_X	= GAME_WIDTH / 2.5f - 30;    //�R���e�B�j���[���Ȃ��ƕ\������e�L�X�g��Y���W

	int nowCursor;              //���ݑI�𒆂̃J�[�\��
	int x;                      //�J�[�\���\���p��X���W
	int alpha;                  //�����x
	int charaType;              //�L�����^�C�v
public:
	GameOver(ISceneChanger* _sceneChanger, Parameter* _parameter);
	void Update();				//�X�V����
	void Draw();				//�`�揈��
	void Select();              //�I������
	void Move();                //�����̏���
};

#endif //GAMEOVER_H_