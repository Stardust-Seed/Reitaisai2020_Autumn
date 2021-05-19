#ifndef AR_GAMEMAIN_H
#define AR_GAMEMAIN_H

#include "SceneManager.h"
#include "GameResource.h"
#include "Parameter.h"

#include "Title.h"
#include "Menu.h"
#include "CharaSelect.h"
#include "Option.h"
#include "OperationExp.h"
#include "LevelSelect.h"
#include "GameScene.h"
#include "GameClear.h"
#include "GameOver.h"
#include "Pausemenu.h"

class GameMain {
	Parameter* parameter;	//�p�����[�^
	SceneManager* sManager;	//�V�[���}�l�[�W���[
	GameResource gameRes;	//�Q�[�����\�[�X

	Title title;				//�^�C�g���V�[��
	Menu menu;					//���j���[�V�[��
	CharaSelect cSelect;		//�L�����I���V�[��
	Option option;				//�ݒ�V�[��
	OperationExp opExp;			//��������V�[��
	LevelSelect levelSelect;	//��Փx�I���V�[��
	GameScene inGame;			//�Q�[���V�[��
	GameClear gameClear;		//�Q�[���N���A�V�[��
	GameOver gameOver;			//�Q�[���I�[�o�[�V�[��
	Pausemenu pauseMenu;		//�|�[�Y���j���[�V�[��

	int fadeCnt;
public:
	GameMain();
	~GameMain();
	void Init();
	bool GameLoop();
};

#endif // !AR_GAMEMAIN_H