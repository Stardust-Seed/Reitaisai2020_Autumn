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
	const static int GAME_Y;    //�R���e�B�j���[����ƕ\������e�L�X�g��Y���W
	const static int MENU_Y;    //�R���e�B�j���[���Ȃ��ƕ\������e�L�X�g��Y���W

	int nowCursor;              //���ݑI�𒆂̃J�[�\��
	int y;                      //�J�[�\���\���p��Y���W
public:
	GameOver(ISceneChanger* _sceneChanger, Parameter* _parameter);
	void Update();				//�X�V����
	void Draw();				//�`�揈��
	void Select();              //�I������
};

#endif //GAMEOVER_H_