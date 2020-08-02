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

	bool pauseFlg;					//ポーズメニューへ移行するかの判定
	bool pauseState;				//ポーズメニューに一度でもなったかの判定
	bool pauseReset;				//ポーズメニューを一度でも解除したかの判定
	
public:
	void Pause();					//ゲーム画面の中断

	void PauseAll();				//ポーズ画面時の処理

	void View();					//表示処理

	void Update();					//更新処理

	void Draw();					//描画処理
};

#endif 
