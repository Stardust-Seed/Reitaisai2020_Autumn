#ifndef _MENU_H_
#define _MENU_H_

#include "BaseScene.h"

#include "Define.h"

/// <summary>
/// メニュータイプ
/// </summary>
enum class  eMenuType {
	Game,		//ゲーム画面
	Option,		//オプション画面
	Title,		//タイトル画面
	GameExit	//ゲーム終了
};

/// <summary>
/// メニュークラス
/// </summary>
class Menu :public BaseScene {
private:
	const float UI_X = (GAME_WIDTH / 2);	//UIのx座標
	const float UI_Y[4]{					//UIのy座標
		(GAME_HEIHGT / 2) - 300,	//プレイ
		(GAME_HEIHGT / 2) - 100,	//オプション
		(GAME_HEIHGT / 2) + 100,	//タイトルへ戻る
		(GAME_HEIHGT / 2) + 300		//ゲーム終了
	};
	const double UI_EXT[2]{					//UIの拡大率
		1.5,	//x
		0.7		//y
	};
	const int UI_PAL		= 255;			//UIのブレンドのパラメータ
	const int UI_FONTSIZE	= 100;			//UIのフォントサイズ

	eMenuType selectMenu;	//選択された項目
	Cursor cursor[4];		//カーソルの色
	unsigned int color[4];	//文字の色
	int fadeCnt;			//フェードカウント

	/// <summary>
	/// 選択メニューを切り替える
	/// </summary>
	/// <param name="_changeMode">切り替えモード</param>
	void SelectMenu(int _changeMode);
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_sceneChanger">シーンチェンジャー</param>
	/// <param name="_parameter">パラメータ</param>
	Menu(ISceneChanger* _sceneChanger, Parameter* _parameter);

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();
};

#endif