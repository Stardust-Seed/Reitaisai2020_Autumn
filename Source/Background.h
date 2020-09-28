#ifndef _BACKGROUND_H
#define _BACKGROUND_H

#include <array>
#include "Star.h"

using namespace std;

/// <summary>
/// 背景タイプ
/// </summary>
enum class eBackgroundType {
	Title,	//タイトル
	Menu,	//メニュー
	Game	//ゲーム
};

/// <summary>
/// 背景クラス
/// </summary>
class Background final {
private:
	const int MAX_STAR = 30;	//最大の星の数
	Star* stars[30];			//星クラス
	
	array<double, 5> starsExtData;
	array<float, 6> starsXData;
	array<float, 20> starsYData;
	int extCnt;
	int xCnt;
	int yCnt;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Background();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 背景を描画する
	/// </summary>
	/// <param name="_buckgroundType">背景のタイプ</param>
	void Draw(eBackgroundType _buckgroundType);
};

#endif // !_BACKGROUND_H