#include <DxLib.h>
#include "SceneManager.h"
#include "CharaSelect.h"
#include "GameClear.h"
#include "GameOver.h"
#include "GameScene.h"
#include "Image.h"
#include "LevelSelect.h"
#include "Menu.h"
#include "OperationExp.h"
#include "Option.h"
#include "Parameter.h"
#include "Pausemenu.h"
#include "Title.h"

/*コンストラクタ*/
SceneManager::SceneManager(GameResource* _gameRes) {
	scenes.push(std::make_shared<Title>(this, &parameter));
	gameRes = _gameRes;
	nowScene = eScene_TITLE;
	frontScene = eScene_TITLE;
	scenes.top()->Init();
	isChange = false;
}

/*更新処理*/
void SceneManager::Update() {

	if (isChange == true) {
		isChange = false;
		return;
	}

	scenes.top()->Update(gameRes);
}

/*描画処理*/
void SceneManager::Draw() {

	if (isChange == true) {
		isChange = false;
		return;
	}

	scenes.top()->Draw(gameRes);
}

/*シーン切り替え処理*/
void SceneManager::SceneChange(eScene _nextScene, Parameter* _parameter,
	const bool _isStack, const bool _isBack) {
	//一つ前のシーンにする処理
	if (_isBack) {
		scenes.pop();
		nowScene = _nextScene;
		return;
	}

	//scenesの中身をすべて削除する
	if (!_isStack) {
		while (!scenes.empty()) {
			scenes.pop();
		}
	}

	//現在のシーンを以前のシーン
	frontScene = nowScene;

	switch (_nextScene) {
	case eScene_TITLE:
		scenes.push(std::make_shared<Title>(this, _parameter));
		nowScene = eScene_TITLE;
		break;
	case eScene_MENU:
		scenes.push(std::make_shared<Menu>(this, _parameter));
		nowScene = eScene_MENU;
		break;
	case eScene_GAME:
		scenes.push(std::make_shared<GameScene>(this, _parameter, gameRes));
		nowScene = eScene_GAME;
		break;
	case eScene_CLAER:
		scenes.push(std::make_shared<GameClear>(this, _parameter));
		nowScene = eScene_CLAER;
		break;
	case eScene_GAMEOVER:
		scenes.push(std::make_shared<GameOver>(this, _parameter));
		nowScene = eScene_GAMEOVER;
		break;
	case eScene_OPTION:
		scenes.push(std::make_shared<Option>(this, _parameter));
		nowScene = eScene_OPTION;
		break;
	case eScene_PAUSEMENU:
		scenes.push(std::make_shared<Pausemenu>(this, _parameter));
		nowScene = eScene_PAUSEMENU;
		break;
	case eScene_CHARASELECT:
		scenes.push(std::make_shared<CharaSelect>(this, _parameter));
		nowScene = eScene_CHARASELECT;
		break;
	case eScene_LEVELSELECT:
		scenes.push(std::make_shared<LevelSelect>(this, _parameter));
		nowScene = eScene_LEVELSELECT;
		break;
	case eScene_OPERATIONEXP:
		scenes.push(std::make_shared<OperationExp>(this, _parameter));
		nowScene = eScene_OPERATIONEXP;
		break;
	}

	isChange = true;
}