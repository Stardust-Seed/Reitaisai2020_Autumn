#ifndef _BaseScene_H
#define _BaseScene_H_

enum EBaseScene
{
	Title,				//�^�C�g�����
	Menu,				//���j���[���
	Game,				//�Q�[�����
	Claer,				//�N���A���
	Gameover,			//�Q�[���I�u�W�F�N�g
	Option,				//�I�v�V����
	Pausemenu,			//�|�[�Y���j���[
	Charaselect,		//�L�����I�����
	Levelselect,		//��Փx�I�����
};

class BaseScene
{
public:
	virtual void Draw() = 0;		//�`�揈��

	virtual void Update() = 0;		//�X�V����
};

#endif
