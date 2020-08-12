#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_

#include "BaseScene.h"

enum Continuity                 //選択させるのに使います
{
	//後々、項目が増えてもいいようにmin,maxの項目を設定しておく
	Continuity_Min,             //最低値
	Continuity_Yes,             //コンティニューする
    Continuity_No,              //コンティニューしない
	Continuity_Max              //最大値
};

class GameOver :public virtual BaseScene{

private:
	const static int GAME_Y;    //イエースこんてぃぬーと表示
	const static int MENU_Y;    //新たな伝説を断念と表示

	int nowCursor;              //現在選択中のカーソル
	int y;                      //カーソル表示用のY座標
public:
	GameOver(ISceneChanger* _sceneChanger);
	void Update();				//更新処理
	void Draw();				//描画処理
	void Select();              //選択処理
};

#endif //GAMEOVER_H_