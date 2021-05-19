#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

//インクルードするやつが多いのでグループ分けして間を分けてる
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
	//それぞれの処理を呼び出すための奴
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
	void Init(GameResource* _gameRes);				//初期化処理
	void Final();									//終了処理
	void Update(GameResource* _gameRes);			//更新処理
	void Draw(GameResource* _gameRes);				//描画処理
	void ChangeScene(GameResource* _gameRes);       //シーン変更処理
};

#endif //GAMESCENE_H_