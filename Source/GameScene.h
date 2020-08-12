#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include "BaseScene.h"
//#include "Castle.h"

class GameScene :public virtual BaseScene {
public:
	GameScene(ISceneChanger* _sceneChanger);
	void Update();				//更新処理
	void Draw();				//描画処理
	void ChangeScene();         //シーン変更処理
};

#endif //GAMESCENE_H_