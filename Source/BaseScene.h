#ifndef _BaseScene_H
#define _BaseScene_H_


enum EBaseScene
{
	Title = 0,				//タイトル画面
	Menu = 1,				//メニュー画面
	Game = 2,				//ゲーム画面
	Claer = 3,				//クリア画面
	Gameover = 4,			//ゲームオブジェクト
	Option = 5,				//オプション
	Pausemenu = 6,			//ポーズメニュー
	Charaselect = 7,		//キャラ選択画面
	Levelselect = 8,		//難易度選択画面
	
};

class BaseScene
{
public:
	virtual void Draw() = 0;		//描画処理

	virtual void Update() = 0;		//更新処理
};
#endif
