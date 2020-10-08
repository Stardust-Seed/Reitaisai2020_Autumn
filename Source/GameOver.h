#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_

#include "BaseScene.h"
#include "Input.h"
#include "Image.h"
#include "BGM.h"
#include "SE.h"
#include "Define.h"
#include "FontHandle.h"
#include "Cursor.h"

class GameOver :public virtual BaseScene{

private:
	const static int GAME_X;    //コンティニューすると表示するテキストのY座標
	const static int MENU_X;    //コンティニューしないと表示するテキストのY座標
	const TCHAR* text1 = "ゲームオーバー";
	const TCHAR* text2 = "コンティニューする";
	const TCHAR* text3 = "コンティニューしない";
	const TCHAR* text4 = "十六夜 咲夜";
	const TCHAR* text5 = "これは...\n今度から美鈴には大きな休暇を与えておくわね...";
	const TCHAR* text6 = "フランドール・S";
	const TCHAR* text7 = "う～ん...もっとキュッとしてドカーンってしたかった～";
	Cursor nowCursor;           //現在選択中のカーソル
	int x;                      //カーソル表示用のX座標
	int alpha;                  //透明度
	int charaType;              //キャラタイプ
	int waitTimer;              //シーン切り替え後少しの間操作を受け付けないようにする
public:
	GameOver(ISceneChanger* _sceneChanger, Parameter* _parameter);
	void Update();				//更新処理
	void Draw();				//描画処理
	void Select();              //選択処理
	void Move();                //動きの処理
};

#endif //GAMEOVER_H_