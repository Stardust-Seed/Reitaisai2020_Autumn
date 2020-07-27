#ifndef _BaseScene_H
#define _BaseScene_H_

enum EBaseScene
{
	TITLE,				//�^�C�g�����
	MENU,				//���j���[���
	GAME,				//�Q�[�����
	CLAER,				//�N���A���
	GAMEOVER,			//�Q�[���I�u�W�F�N�g
	OPTION,				//�I�v�V����
	PAUSEMENU,			//�|�[�Y���j���[
	CHARASELECT,		//�L�����I�����
	LEVELSELECT,		//��Փx�I�����
};

class BaseScene
{
public:
	virtual void Draw() = 0;		//�`�揈��

	virtual void Update() = 0;		//�X�V����
};

#endif
