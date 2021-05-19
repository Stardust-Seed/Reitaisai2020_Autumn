#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager() {

}

//初期化処理
void SceneManager::Init(GameResource* _gameRes) {
	nowScene = "";
}

//終了処理
void SceneManager::Final() {
	//登録しておいたシーンを空にする
	scenes.clear();
}

//更新処理
void SceneManager::Update(GameResource* _gameRes) {
	stackScene.top()->Update(_gameRes);
}

//描画処理
void SceneManager::Draw(GameResource* _gameRes) {
	stackScene.top()->Draw(_gameRes);
}

//シーン切り替え処理
void SceneManager::SceneChange(std::string _nextSceneName, bool _isStack, bool _isBack,
	GameResource* _gameRes) {
	//次のシーンを現在のシーンに
	nowScene = _nextSceneName;

	//一つ前のシーンに戻る
	if (_isBack) {
		stackScene.top()->Final();
		stackScene.pop();
		return;
	}

	//stackSceneの中身を全て削除する
	if (!_isStack) {
		while (!stackScene.empty()) {
			stackScene.pop();
		}
	}

	//次のシーンを取得する
	Scene* scene = GetScene(_nextSceneName);

	//シーンが空の場合強制終了する
	if (scene == nullptr)exit(EXIT_FAILURE);

	//stackSceneに次のシーンを格納する
	stackScene.push(scene);

	//次のシーンを初期化する
	stackScene.top()->Init(_gameRes);
}

//シーンを登録
void SceneManager::SetScene(std::string _nextSceneName, Scene* _sceneClass) {
	scenes[_nextSceneName] = _sceneClass;
}

//シーンを取得
Scene* SceneManager::GetScene(std::string _nextSceneName)const {
	auto it = scenes.find(_nextSceneName);		//指定キーを取得

	//指定のキーが存在しない場合
	if (scenes.end() == it) {
		return nullptr;
	}
	//存在した場合
	else {
		return it->second;
	}
}