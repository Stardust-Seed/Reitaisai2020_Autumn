#ifndef _PAUSEMENU_H
#define _PAUSEMENU_H

const static int PGAME_Y = 200;		//�u�Q�[����ʂɖ߂�v�����̈ʒu
const static int PEND_Y = 300;		//�u�Q�[���I���v������y�ʒu

enum ePausetype
{
	ePausetype_Game,				//�Q�[����ʂɖ߂�
	ePausetype_Menu,				//���j���[��ʂɖ߂�
	ePausetype_Num,					//���ڂ̐�
};

class Pausemenu 
{

private:
	int NowSelect = 0;				//���ݑI������Ă��鍀��
	int y;
	
public:
	void Update();					//�X�V����

	void Draw();					//�`�揈��
};

#endif 