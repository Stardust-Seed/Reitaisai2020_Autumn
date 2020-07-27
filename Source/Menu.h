#ifndef _MENU_H_
#define _MENU_H_

#include "BaseScene.h"

const static int GAME_Y = 240;		//「ゲーム」文字のy位置
const static int CONFIG_Y = 270;    //「設定」文字のy位置

enum eMenutype
{
	eMenutype_Menu,		//メニュー
	eMenutype_Game,		//ゲーム画面
	eMenutype_Option,	//オプション
	eMenutype_Num,		//項目の数
};

class Menu:public virtual BaseScene
{
private:
	int NowSelect;				//今、選択されてる項目
	int y = 0;							

public:
	void SelectMenu();			//メニュー項目の選択

	void Update();				//更新処理

	void Draw();				//描画処理
};

#endif