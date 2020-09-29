#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

//インクルードするやつが多いのでグループ分けして間を分けてる
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
	GameScene(ISceneChanger* _sceneChanger, Parameter* _parameter);
	void Update();				//更新処理
	void Draw();				//描画処理
	void ChangeScene();         //シーン変更処理
};

#endif //GAMESCENE_H_