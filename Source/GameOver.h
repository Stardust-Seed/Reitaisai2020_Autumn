#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_

#include "BaseScene.h"

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
	const static int GAME_Y;    //�C�G�[�X����Ă��ʁ[�ƕ\��
	const static int MENU_Y;    //�V���ȓ`����f�O�ƕ\��

	int nowCursor;              //���ݑI�𒆂̃J�[�\��
	int y;                      //�J�[�\���\���p��Y���W
public:
	GameOver(ISceneChanger* _sceneChanger);
	void Update();				//�X�V����
	void Draw();				//�`�揈��
	void Select();              //�I������
};

#endif //GAMEOVER_H_