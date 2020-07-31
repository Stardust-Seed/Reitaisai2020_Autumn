#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include "BaseScene.h"
#include "Castle.h"

class GameScene :public virtual BaseScene{

private:
	int nowScene;               //現在選択中のシーン

public:
	GameScene();
	void Update() {};				//更新処理
	void Update(Castle* _castle);
	void Draw();				//描画処理
	void ChangeScene(Castle* _castle);         //シーン変更処理
};

#endif //GAMESCENE_H_