#ifndef _BaseScene_H
#define _BaseScene_H_


enum EBaseScene
{
	Title = 0,				//�^�C�g�����
	Menu = 1,				//���j���[���
	Game = 2,				//�Q�[�����
	Claer = 3,				//�N���A���
	Gameover = 4,			//�Q�[���I�u�W�F�N�g
	Option = 5,				//�I�v�V����
	Pausemenu = 6,			//�|�[�Y���j���[
	Charaselect = 7,		//�L�����I�����
	Levelselect = 8,		//��Փx�I�����
	
};

class BaseScene
{
public:
	virtual void Draw() = 0;		//�`�揈��

	virtual void Update() = 0;		//�X�V����
};
#endif
