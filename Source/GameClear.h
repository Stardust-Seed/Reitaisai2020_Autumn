#ifndef _GAMECLEAR_H
#define _GAMECLEAR_H

#include "BaseScene.h"
#include "Input.h"
#include "Image.h"
#include "BGM.h"
#include "SE.h"
#include "Define.h"
#include "FontHandle.h"
#include "Cursor.h"

class GameClear final :public BaseScene {
private:
	const static int GAME_X;   //「ゲームに戻る」テキスト表示のX座標
	const static int TITLE_X;     //「タイトルに戻る」テキスト表示のX座標

	Cursor nowCursor;           //現在選択中のカーソル
	int x;                      //カーソル表示用のX座標
	int alpha;                  //透明度
	int charaType;              //キャラタイプ
public:
	GameClear(ISceneChanger* _sceneChanger, Parameter* _parameter);
	void Update();				//更新処理
	void Draw();				//描画処理
	void Select();              //選択処理
	void Move();                //動きの処理
};

#endif // !_GAMECLEAR_H