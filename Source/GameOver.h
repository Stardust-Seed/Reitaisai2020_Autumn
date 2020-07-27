#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_

#include "BaseScene.h"

enum Continuity                 //�I��������̂Ɏg���܂�
{
	Continuity_Yes,             //�R���e�B�j���[����
    Continuity_No,              //�R���e�B�j���[���Ȃ�
	Continuity_NULL             //��
};

class GameOver :public virtual BaseScene{

private:
	const static int GAME_Y;    //�C�G�[�X����Ă��ʁ[�ƕ\��
	const static int MENU_Y;    //�V���ȓ`����f�O�ƕ\��

	int nowScene;               //���ݑI�𒆂̃V�[��
	int nowCursor;              //���ݑI�𒆂̃J�[�\��
	int y;                      //�J�[�\���\���p��Y���W

public:
	GameOver();

	void Update();				//�X�V����
	void Draw();				//�`�揈��
};

#endif //GAMEOVER_H_