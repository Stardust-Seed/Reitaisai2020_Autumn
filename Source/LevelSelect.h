#ifndef _LEVELSELECT_H
#define _LEVELSELECT_H

#include <string>
#include "BaseScene.h"
#include "Cursor.h"
#include "Define.h"
using namespace std;

/// <summary>
/// 選択中のレベル
/// </summary>
enum class eLevelType {
	Easy,		//簡単
	Normal,		//普通
	Hard,		//難しい
};

/// <summary>
/// 難易度選択クラス
/// </summary>
class LevelSelect final :public BaseScene {
private:
	const float UI_X = (GAME_WIDTH / 2);	//UIのx座標
	const float UI_Y[3] = {					//UIのy座標
		(GAME_HEIHGT / 2) - 300,	//Easy
		(GAME_HEIHGT / 2),			//Normal
		(GAME_HEIHGT / 2) + 300		//Hard
	};
	const double UI_EXT		= 1.0;	//UIの拡大率
	const int UI_PAL		= 255;	//UIのブレンドのパラメータ
	const int UI_FONTSIZE	= 100;	//UIのフォントサイズ

	eLevelType selectLevel;	//選択されたレベル
	Cursor cursor[3];		//カーソルの色
	unsigned int color[3];	//文字の色
	bool isClear[3];		//クリアフラグ
	bool isChange;			//切り替えフラグ

	/// <summary>
	/// 選択レベルを切り替える
	/// </summary>
	/// <param name="_changeMode">切り替えモード</param>
	void ChangeLevel(int _changeMode);

	/// <summary>
	/// 引数のカーソルを各カーソルにセットする
	/// </summary>
	/// <param name="_easy">Easyのカーソル</param>
	/// <param name="_normal">Normalのカーソル</param>
	/// <param name="_hard">Hardのカーソル</param>
	void SetCursor(Cursor _easy, Cursor _normal, Cursor _hard);

	/// <summary>
	/// 引数に対応する色をセットする
	/// </summary>
	/// <param name="_easy">Easyのカーソル</param>
	/// <param name="_normal">Normalのカーソル</param>
	/// <param name="_hard">Hardのカーソル</param>
	void SetColor(unsigned int _easy, unsigned int _normal, unsigned int _hard);

	/// <summary>
	/// クリアフラグをセットする
	/// </summary>
	/// <param name="_isClear">クリアフラグ</param>
	/// <param name="_level">セットするレベル</param>
	void SetIsClear(int _isClear, int _level);

	/// <summary>
	/// クリア表示する
	/// </summary>
	/// <param name="_level">表示するレベル</param>
	void ClearDraw(eLevelType _level);
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_sceneChanger">シーン切り替えクラス</param>
	/// <param name="_parameter">パラメータ</param>
	LevelSelect(ISceneChanger* _sceneChanger, Parameter* _parameter);

	/// <summary>
	/// デストラクタ
	/// </summary>	
	~LevelSelect() = default;

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update(GameResource* _gameRes);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw(GameResource* _gameRes);
};

#endif // !_LEVELSELECT_H