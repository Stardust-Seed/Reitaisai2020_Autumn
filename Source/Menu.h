#ifndef _MENU_H_
#define _MENU_H_

#include "BaseScene.h"

const static int GAME_Y = 240;		//「ゲーム」文字のy位置
const static int OPTOIN_Y = 270;    //「オプション」文字のy位置
const static int END_Y = 300;		//「ゲーム終了」文字のy位置

enum eMenutype
{
	eMenutype_Game,		//ゲーム画面
	eMenutype_Option,	//オプション
	eMenutype_Title,	//タイトル画面
	eMenutype_Num,		//項目の数
};

class Menu:public virtual BaseScene
{
private:
	int NowSelect = 0;				//今、選択されてる項目
	int y = 0;					
public:
	Menu(ISceneChanger* _sceneChanger, Parameter* _parameter);

	void SelectMenu();			//メニュー項目の選択

	void Update();				//更新処理

	void Draw();				//描画処理
};

#endif