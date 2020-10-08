#ifndef _PAUSEMENU_H
#define _PAUSEMENU_H

#include "BaseScene.h"
#include "Define.h"

const static int PGAME_Y = (GAME_HEIHGT / 2) - 300;		//「ゲーム画面に戻る」文字の位置
const static int PEND_Y = (GAME_HEIHGT / 2)+300;		//「操作説明画面」文字のy位置
const static int PGUIDE_Y = (GAME_HEIHGT / 2);		//「ゲーム終了」文字のy位置

enum ePausetype
{
	ePausetype_Game,				//ゲーム画面に戻る
	ePausetype_Menu,				//メニュー画面に戻る
	ePausetype_Guide,				//操作説明画面へ
	ePausetype_Num,					//項目の数
};

class Pausemenu :public BaseScene {
private:
	int NowSelect = 0;				//現在選択されている項目
	int y;
public:
	Pausemenu(ISceneChanger* _sceneChanger, Parameter* _parameter);

	void PauseAll();				//ポーズ画面時の処理
	void Update();					//更新処理
	void Draw();					//描画処理
};

#endif 
