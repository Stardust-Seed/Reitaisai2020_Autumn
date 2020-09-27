#ifndef _MENU_H_
#define _MENU_H_

#include "BaseScene.h"

const static int GAME_Y = 240;		//�u�Q�[���v������y�ʒu
const static int OPTOIN_Y = 270;    //�u�I�v�V�����v������y�ʒu
const static int END_Y = 300;		//�u�Q�[���I���v������y�ʒu

enum eMenutype
{
	eMenutype_Game,		//�Q�[�����
	eMenutype_Option,	//�I�v�V����
	eMenutype_Title,	//�^�C�g�����
	eMenutype_Num,		//���ڂ̐�
};

class Menu:public virtual BaseScene
{
private:
	int NowSelect = 0;				//���A�I������Ă鍀��
	int y = 0;					
public:
	Menu(ISceneChanger* _sceneChanger, Parameter* _parameter);

	void SelectMenu();			//���j���[���ڂ̑I��

	void Update();				//�X�V����

	void Draw();				//�`�揈��
};

#endif