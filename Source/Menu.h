#ifndef _MENU_H_
#define _MENU_H_

#include "BaseScene.h"

const static int GAME_Y = 240;		//�u�Q�[���v������y�ʒu
const static int CONFIG_Y = 270;    //�u�ݒ�v������y�ʒu

enum eMenutype
{
	eMenutype_Menu,		//���j���[
	eMenutype_Game,		//�Q�[�����
	eMenutype_Option,	//�I�v�V����
	eMenutype_Num,		//���ڂ̐�
};

class Menu:public virtual BaseScene
{
private:
	int NowSelect;				//���A�I������Ă鍀��
	int y = 0;							

public:
	void SelectMenu();			//���j���[���ڂ̑I��

	void Update();				//�X�V����

	void Draw();				//�`�揈��
};

#endif