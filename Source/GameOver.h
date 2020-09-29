#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_

#include "BaseScene.h"
#include "Input.h"
#include "Image.h"
#include "BGM.h"
#include "SE.h"
#include "Define.h"
#include "FontHandle.h"

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
	const static int GAME_X = GAME_WIDTH / 7.5f - 45;    //コンティニューすると表示するテキストのY座標
	const static int MENU_X	= GAME_WIDTH / 2.5f - 30;    //コンティニューしないと表示するテキストのY座標

	int nowCursor;              //現在選択中のカーソル
	int x;                      //カーソル表示用のX座標
	int alpha;                  //透明度
	int charaType;              //キャラタイプ
public:
	GameOver(ISceneChanger* _sceneChanger, Parameter* _parameter);
	void Update();				//更新処理
	void Draw();				//描画処理
	void Select();              //選択処理
	void Move();                //動きの処理
};

#endif //GAMEOVER_H_