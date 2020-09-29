#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

//�C���N���[�h�����������̂ŃO���[�v�������ĊԂ𕪂��Ă�
#include "BaseScene.h"

#include "EnemyManager.h"
#include "EventManager.h"

#include "BasePlayer.h"
#include "BulletManager.h"
#include "ItemManager.h"
#include "BuffManager.h"
#include "CastleManager.h"

#include "TimeLimit.h"
#include "Ui.h"

class GameScene :public virtual BaseScene {

private:
	//���ꂼ��̏������Ăяo�����߂̓z
	BasePlayer* player;
	BulletManager* bulletManager;
	EventManager* eventManager;
	EnemyManager* enemyManager;
	ItemManager* itemManager;
	BuffManager* buffManager;
	CastleManager* castleManager;
	TimeLimit* timeLimit;
	UI* ui;

public:
	GameScene(ISceneChanger* _sceneChanger, Parameter* _parameter);
	void Update();				//�X�V����
	void Draw();				//�`�揈��
	void ChangeScene();         //�V�[���ύX����
};

#endif //GAMESCENE_H_