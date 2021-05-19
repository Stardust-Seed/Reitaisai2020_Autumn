#ifndef _MENU_H_
#define _MENU_H_

#include "Scene.h"
#include "Define.h"
#include "Cursor.h"

/// <summary>
/// メニュータイプ
/// </summary>
enum class  eMenuType {
	Game,			//ゲーム画面
	Option,			//オプション画面
	OperationExp,	//操作説明画面
	Title,			//タイトル画面
	GameExit		//ゲーム終了
};

/// <summary>
/// メニュークラス
/// </summary>
class Menu final :public Scene {
private:
	const float UI_X = (GAME_WIDTH / 2);	//UIのx座標
	const float UI_Y[5]{					//UIのy座標
		(GAME_HEIHGT / 2) - 400,			//プレイ
		(GAME_HEIHGT / 2) - 200,			//オプション
		(GAME_HEIHGT / 2),
		(GAME_HEIHGT / 2) + 200,			//タイトルへ戻る
		(GAME_HEIHGT / 2) + 400				//ゲーム終了
	};
	const double UI_EXT[2]{					//UIの拡大率
		1.5,	//x
		0.7		//y
	};
	const int UI_PAL		= 255;			//UIのブレンドのパラメータ
	const int UI_FONTSIZE	= 100;			//UIのフォントサイズ

	eMenuType selectMenu;	//選択された項目
	Cursor cursor[5];		//カーソルの色
	unsigned int color[5];	//文字の色


	//選択メニューを切り替える
	void SelectMenu(int _changeMode);
public:

	//コンストラクタ
	Menu();

	//デストラクタ
	~Menu() = default;

	//初期化処理
	void Init(GameResource* _gameRes);

	//更新処理
	void Update(GameResource* _gameRes);

	//描画処理
	void Draw(GameResource* _gameRes);
};

#endif