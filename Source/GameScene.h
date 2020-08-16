#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

//�C���N���[�h�����������̂ŃO���[�v�������ĊԂ𕪂��Ă�
#include "BaseScene.h"

#include "BaseEnemy.h"
#include "EnemyManager.h"
#include "Fairy_Endurance.h"
#include "Fairy_Speed.h"

#include "BasePlayer.h"
#include "BulletManager.h"

#include "Castle.h"

#include "TimeLimit.h"
#include "Ui.h"

#include "Input.h"
#include "SE.h"
#include "BGM.h"

class GameScene :public virtual BaseScene {

private:
	//���ꂼ��̏������Ăяo�����߂̓z
	BasePlayer* player;
	BulletManager* bulletManager;
	EnemyManager* enemyManager;
	Castle* castle;
	TimeLimit* timeLimit;
	UI* ui;

public:
	GameScene(ISceneChanger* _sceneChanger);
	void Update();				//�X�V����
	void Draw();				//�`�揈��
	void ChangeScene();         //�V�[���ύX����
};

#endif //GAMESCENE_H_