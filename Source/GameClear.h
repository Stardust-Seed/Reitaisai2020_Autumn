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
#include "File.h"

class GameClear final :public BaseScene {
private:
	const static int GAME_X;   //「ゲームに戻る」テキスト表示のX座標
	const static int TITLE_X;     //「タイトルに戻る」テキスト表示のX座標
	const TCHAR* text1 = "ゲームクリア！";
	const TCHAR* text2 = "もう一度挑戦";
	const TCHAR* text3 = "メニューに戻る";
	const TCHAR* text4 = "十六夜 咲夜";
	const TCHAR* text5 = "フフッ 紅魔館のメイド長として当然のことだわ";
	const TCHAR* text6 = "フランドール・S";
	const TCHAR* text7 = "フフフッ お姉さまに褒めてもらうんだ～";

	Cursor nowCursor;           //現在選択中のカーソル
	int x;                      //カーソル表示用のX座標
	int alpha;                  //透明度
	int charaType;              //キャラタイプ
	int waitTimer;              //シーン切り替え後少しの間操作を受け付けないようにする
public:
	GameClear(ISceneChanger* _sceneChanger, Parameter* _parameter);
	void Update(GameResource* _gameRes);				//更新処理
	void Draw(GameResource* _gameRes);				//描画処理
	void Select();              //選択処理
	void Move();                //動きの処理
};

#endif // !_GAMECLEAR_H