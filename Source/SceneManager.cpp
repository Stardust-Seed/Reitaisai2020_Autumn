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

/*�R���X�g���N�^*/
SceneManager::SceneManager(GameResource* _gameRes) {
	scenes.push(std::make_shared<Title>(this, &parameter));
	gameRes = _gameRes;
	nowScene = eScene_TITLE;
	frontScene = eScene_TITLE;
	scenes.top()->Init();
	isChange = false;
}

/*�X�V����*/
void SceneManager::Update() {

	if (isChange == true) {
		isChange = false;
		return;
	}

	scenes.top()->Update(gameRes);
}

/*�`�揈��*/
void SceneManager::Draw() {

	if (isChange == true) {
		isChange = false;
		return;
	}

	scenes.top()->Draw(gameRes);
}

/*�V�[���؂�ւ�����*/
void SceneManager::SceneChange(eScene _nextScene, Parameter* _parameter,
	const bool _isStack, const bool _isBack) {
	//��O�̃V�[���ɂ��鏈��
	if (_isBack) {
		scenes.pop();
		nowScene = _nextScene;
		return;
	}

	//scenes�̒��g�����ׂč폜����
	if (!_isStack) {
		while (!scenes.empty()) {
			scenes.pop();
		}
	}

	//���݂̃V�[�����ȑO�̃V�[��
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