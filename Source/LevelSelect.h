#ifndef _LEVELSELECT_H
#define _LEVELSELECT_H

#include "BaseScene.h"
#include "Background.h"

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
	const int CURSOR_UP		= 0;	//カーソルが上がった(定数)
	const int CURSOR_DOWN	= 1;	//カーソルが下がった(定数)

	eLevelType selectLevel;	//選択されたレベル
	eLevelType tmpLevel;	//変更前のレベル

	//Easy座標
	float easyX1;
	float easyX2;
	float easyY1;
	float easyY2;

	//Normal座標
	float normalX1;
	float normalX2;
	float normalY1;
	float normalY2;

	//Hard座標
	float hardX1;
	float hardX2;
	float hardY1;
	float hardY2;

	int animationCnt;	//アニメーションカウント
	bool isChange;		//切り替えフラグ

	void ChangeLevel();

	/// <summary>
	/// UIの描画処理
	/// </summary>
	/// <param name="_x1">始点のx座標</param>
	/// <param name="_y1">始点のy座標</param>
	/// <param name="_x2">終点のx座標</param>
	/// <param name="_y2">終点のy座標</param>
	/// <param name="_color">UIの色</param>
	/// <param name="_text">表示するテキスト</param>
	/// <param name="_levelType">このUIのレベル</param>
	void DrawUIBox(float _x1, float _y1, float _x2, float _y2, unsigned int _color,
		const char* _text, eLevelType _levelType);

	/// <summary>
	/// UIの切り替えアニメーション
	/// </summary>
	void Animation();
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_sceneChanger">シーン切り替えクラス情報</param>
	LevelSelect(ISceneChanger* _sceneChanger, Parameter* _parameter);

	/// <summary>
	/// デストラクタ
	/// </summary>	
	~LevelSelect() = default;

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();
};

#endif // !_LEVELSELECT_H