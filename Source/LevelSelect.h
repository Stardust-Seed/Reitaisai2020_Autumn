#ifndef _LEVELSELECT_H
#define _LEVELSELECT_H

#include <string>
#include "BaseScene.h"

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
	const int CURSOR_UP		= 0;	//カーソルが上がった(定数)
	const int CURSOR_DOWN	= 1;	//カーソルが下がった(定数)

	string EASY		= "Easy";
	string NORMAL	= "Normal";
	string HARD		= "Hard";

	eLevelType selectLevel;	//選択されたレベル
	eLevelType tmpLevel;	//変更前のレベル

	//Easy座標
	float easyX;
	float easyY;

	//Normal座標
	float normalX;
	float normalY;

	//Hard座標
	float hardX;
	float hardY;

	int animationCnt;	//アニメーションカウント
	bool isChange;		//切り替えフラグ

	void ChangeLevel(int _changeMode);

	void DrawUIBox(float _x, float _y, string _text,
		eLevelType _levelType, Cursor _cursor);

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