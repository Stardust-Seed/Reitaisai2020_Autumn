#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H

#include <stack>
#include <memory>
#include "BaseScene.h"
#include "ISceneChanger.h"
#include "GameResource.h"

//シーン管理クラス
class SceneManager final :public ISceneChanger {
private:
	Parameter parameter;								//パラメーター
	GameResource* gameRes;								//ゲームリソース
	std::stack<std::shared_ptr<BaseScene>> scenes;		//シーン

	bool isChange;
	eScene nowScene;
	eScene frontScene;
public:
	SceneManager(GameResource* _gameRes);							//コンストラクタ
	void Update();													//更新処理
	void Draw();													//描画処理
	void SceneChange(eScene _nextScene, Parameter* _parameter,		//シーン切り替え処理
		const bool _isStack, const bool _isBack);

	eScene GetNowScene() { return nowScene; }						//現在のシーンを取得
};

#endif // !_SCENEMANAGER_H