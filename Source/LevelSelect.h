#ifndef _LEVELSELECT_H
#define _LEVELSELECT_H

#include "BaseScene.h"
#include "Background.h"

/// <summary>
/// 選択中のレベル
/// </summary>
enum class eSelectLevel {
	Easy,
	Normal,
	Hard,
};

/// <summary>
/// 難易度選択クラス
/// </summary>
class LevelSelect final :public BaseScene {
private:
	Background background;
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