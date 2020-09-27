#include "SceneManager.h"
#include "GameClear.h"
#include "GameOver.h"
#include "GameScene.h"
#include "Menu.h"
#include "Option.h"
#include "Charaselect.h"
#include "Pausemenu.h"
#include "Title.h"

/*コンストラクタ*/
SceneManager::SceneManager() {
	scenes.push(std::make_shared<Charaselect>(this));
}

/*更新処理*/
void SceneManager::Update() {
	scenes.top()->Update();
}

/*描画処理*/
void SceneManager::Draw() {
	scenes.top()->Draw();
}

/*シーン切り替え処理*/
void SceneManager::SceneChange(eScene _nextScene, const bool _isStack, const bool _isBack) {
	//一つ前のシーンにする処理
	if (_isBack) {
		scenes.pop();
		return;
	}

	//scenesの中身をすべて削除する
	if (!_isStack) {
		while (!scenes.empty()) {
			scenes.pop();
		}
	}


	switch (_nextScene) {
	case eScene_TITLE:
		scenes.push(std::make_shared<Title>(this));
		break;
	case eScene_MENU:
		scenes.push(std::make_shared<Menu>(this));
		break;
	case eScene_GAME:
		scenes.push(std::make_shared<GameScene>(this));
		break;
	case eScene_CLAER:
		scenes.push(std::make_shared<GameClear>(this));
		break;
	case eScene_GAMEOVER:
		scenes.push(std::make_shared<GameOver>(this));
		break;
	case eScene_OPTION:
		scenes.push(std::make_shared<Option>(this));
		break;
	case eScene_PAUSEMENU:
		scenes.push(std::make_shared<Pausemenu>(this));
		break;
	case eScene_CHARASELECT:
		scenes.push(std::make_shared<Charaselect>(this));
		break;
	case eScene_LEVELSELECT:
		break;
	}
}