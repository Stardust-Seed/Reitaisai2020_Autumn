#ifndef _BASESCENE_H
#define _BASESCENE_H

#include "ISceneChanger.h"

class ISceneChanger;

enum eScene
{
	eScene_TITLE,			//�^�C�g�����
	eScene_MENU,			//���j���[���
	eScene_GAME,			//�Q�[�����
	eScene_CLAER,			//�N���A���
	eScene_GAMEOVER,		//�Q�[���I�u�W�F�N�g
	eScene_OPTION,			//�I�v�V����
	eScene_PAUSEMENU,		//�|�[�Y���j���[
	eScene_CHARASELECT,		//�L�����I�����
	eScene_LEVELSELECT,		//��Փx�I�����
};

class BaseScene {
protected:
	ISceneChanger* sceneChanger;	//�V�[���؂�ւ��̃C���^�[�t�F�C�X�N���X
public:
	BaseScene(ISceneChanger* _sceneChanger);
	virtual ~BaseScene() = default;
	virtual void Draw() = 0;		//�`�揈��
	virtual void Update() = 0;		//�X�V����
};


#endif // !_BASESCENE_H