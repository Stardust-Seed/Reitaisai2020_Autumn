#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H

#include <unordered_map>
#include <string>
#include <stack>
#include "GameResource.h"

class Scene;

//シーン管理クラス
class SceneManager final {
private:
	std::unordered_map <std::string, Scene*> scenes;	//登録したシーン
	std::stack<Scene*> stackScene;						//実行するシーン

	std::string nowScene;								//現在のシーン

	Scene* GetScene(std::string _sceneName)const;		//シーンを取得する
public:
	SceneManager();										//コンストラクタ
	void Init(GameResource* _gameRes);					//初期化処理
	void Final();										//終了処理
	void Update(GameResource* _gameRes);				//更新処理
	void Draw(GameResource* _gameRes);					//描画処理

	void SetScene(std::string _sceneName, Scene* _sceneClass);					//シーンを登録する
	void SceneChange(std::string _nextSceneName, bool _isStack, bool _isBack,
		GameResource* _gameRes);												//シーン切り替え処理

	std::string GetNowScene() { return nowScene; }		//現在のシーンを取得する
};

#endif // !_SCENEMANAGER_H