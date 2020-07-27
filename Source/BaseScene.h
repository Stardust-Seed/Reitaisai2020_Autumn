#ifndef _BaseScene_H
#define _BaseScene_H_

enum EBaseScene
{
	TITLE,				//タイトル画面
	MENU,				//メニュー画面
	GAME,				//ゲーム画面
	CLAER,				//クリア画面
	GAMEOVER,			//ゲームオブジェクト
	OPTION,				//オプション
	PAUSEMENU,			//ポーズメニュー
	CHARASELECT,		//キャラ選択画面
	LEVELSELECT,		//難易度選択画面
};

class BaseScene
{
public:
	virtual void Draw() = 0;		//描画処理

	virtual void Update() = 0;		//更新処理
};

#endif
