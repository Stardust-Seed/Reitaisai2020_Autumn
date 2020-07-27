#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_

#include "BaseScene.h"

enum Continuity                 //選択させるのに使います
{
	Continuity_Yes,             //コンティニューする
    Continuity_No,              //コンティニューしない
	Continuity_NULL             //無
};

class GameOver :public virtual BaseScene{

private:
	const static int GAME_Y;    //イエースこんてぃぬーと表示
	const static int MENU_Y;    //新たな伝説を断念と表示

	int nowScene;               //現在選択中のシーン
	int nowCursor;              //現在選択中のカーソル
	int y;                      //カーソル表示用のY座標

public:
	GameOver();

	void Update();				//更新処理
	void Draw();				//描画処理
};

#endif //GAMEOVER_H_