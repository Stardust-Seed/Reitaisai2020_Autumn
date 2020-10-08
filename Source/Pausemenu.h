#ifndef _PAUSEMENU_H
#define _PAUSEMENU_H

#include "BaseScene.h"
#include "Define.h"

const static int PGAME_Y = (GAME_HEIHGT / 2) - 300;		//�u�Q�[����ʂɖ߂�v�����̈ʒu
const static int PEND_Y = (GAME_HEIHGT / 2)+300;		//�u���������ʁv������y�ʒu
const static int PGUIDE_Y = (GAME_HEIHGT / 2);		//�u�Q�[���I���v������y�ʒu

enum ePausetype
{
	ePausetype_Game,				//�Q�[����ʂɖ߂�
	ePausetype_Menu,				//���j���[��ʂɖ߂�
	ePausetype_Guide,				//���������ʂ�
	ePausetype_Num,					//���ڂ̐�
};

class Pausemenu :public BaseScene {
private:
	int NowSelect = 0;				//���ݑI������Ă��鍀��
	int y;
public:
	Pausemenu(ISceneChanger* _sceneChanger, Parameter* _parameter);

	void PauseAll();				//�|�[�Y��ʎ��̏���
	void Update();					//�X�V����
	void Draw();					//�`�揈��
};

#endif 
