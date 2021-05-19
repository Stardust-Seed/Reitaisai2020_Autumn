#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

//�C���N���[�h�����������̂ŃO���[�v�������ĊԂ𕪂��Ă�
#include "Define.h"
#include "Scene.h"

#include "EnemyManager.h"
#include "EventManager.h"

#include "BasePlayer.h"
#include "BulletManager.h"
#include "ItemManager.h"
#include "BuffManager.h"
#include "CastleManager.h"

#include "TimeLimit.h"
#include "Ui.h"

class GameScene :public virtual Scene {

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
	GameScene();
	~GameScene();
	void Init(GameResource* _gameRes);				//����������
	void Final();									//�I������
	void Update(GameResource* _gameRes);			//�X�V����
	void Draw(GameResource* _gameRes);				//�`�揈��
	void ChangeScene(GameResource* _gameRes);       //�V�[���ύX����
};

#endif //GAMESCENE_H_