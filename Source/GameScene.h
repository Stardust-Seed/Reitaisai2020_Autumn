#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

//インクルードするやつが多いのでグループ分けして間を分けてる
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
	//それぞれの処理を呼び出すための奴
	BasePlayer* player;
	BulletManager* bulletManager;
	EnemyManager* enemyManager;
	Castle* castle;
	TimeLimit* timeLimit;
	UI* ui;

public:
	GameScene(ISceneChanger* _sceneChanger);
	void Update();				//更新処理
	void Draw();				//描画処理
	void ChangeScene();         //シーン変更処理
};

#endif //GAMESCENE_H_