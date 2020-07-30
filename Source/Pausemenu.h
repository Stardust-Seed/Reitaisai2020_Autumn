#ifndef _PAUSEMENU_H
#define _PAUSEMENU_H

const static int PGAME_Y = 200;		//「ゲーム画面に戻る」文字の位置
const static int PEND_Y = 300;		//「ゲーム終了」文字のy位置

enum ePausetype
{
	ePausetype_Game,				//ゲーム画面に戻る
	ePausetype_Menu,				//メニュー画面に戻る
	ePausetype_Num,					//項目の数
};

class Pausemenu 
{

private:
	int NowSelect = 0;				//現在選択されている項目
	int y;
	
public:
	void Update();					//更新処理

	void Draw();					//描画処理
};

#endif 
