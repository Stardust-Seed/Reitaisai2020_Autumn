#ifndef _BaseScene_H
#define _BaseScene_H_

enum EBaseScene
{
	Title,				//タイトル画面
	Menu,				//メニュー画面
	Game,				//ゲーム画面
	Claer,				//クリア画面
	Gameover,			//ゲームオブジェクト
	Option,				//オプション
	Pausemenu,			//ポーズメニュー
	Charaselect,		//キャラ選択画面
	Levelselect,		//難易度選択画面
};

class BaseScene
{
public:
	virtual void Draw() = 0;		//描画処理

	virtual void Update() = 0;		//更新処理
};

#endif
