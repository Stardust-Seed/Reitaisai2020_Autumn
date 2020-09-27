#include "SceneManager.h"
#include "Charaselect.h"
#include "GameClear.h"
#include "GameOver.h"
#include "GameScene.h"
#include "LevelSelect.h"
#include "Menu.h"
#include "Option.h"
#include "Parameter.h"
#include "Pausemenu.h"
#include "Title.h"

/*�R���X�g���N�^*/
SceneManager::SceneManager() {
	scenes.push(std::make_shared<GameScene>(this, &parameter));
}

/*�X�V����*/
void SceneManager::Update() {
	scenes.top()->Update();
}

/*�`�揈��*/
void SceneManager::Draw() {
	scenes.top()->Draw();
}

/*�V�[���؂�ւ�����*/
void SceneManager::SceneChange(eScene _nextScene, Parameter* _parameter,
	const bool _isStack, const bool _isBack) {
	//��O�̃V�[���ɂ��鏈��
	if (_isBack) {
		scenes.pop();
		return;
	}

	//scenes�̒��g�����ׂč폜����
	if (!_isStack) {
		while (!scenes.empty()) {
			scenes.pop();
		}
	}


	switch (_nextScene) {
	case eScene_TITLE:
		scenes.push(std::make_shared<Title>(this, _parameter));
		break;
	case eScene_MENU:
		scenes.push(std::make_shared<Menu>(this, _parameter));
		break;
	case eScene_GAME:
		scenes.push(std::make_shared<GameScene>(this, _parameter));
		break;
	case eScene_CLAER:
		scenes.push(std::make_shared<GameClear>(this, _parameter));
		break;
	case eScene_GAMEOVER:
		scenes.push(std::make_shared<GameOver>(this, _parameter));
		break;
	case eScene_OPTION:
		scenes.push(std::make_shared<Option>(this, _parameter));
		break;
	case eScene_PAUSEMENU:
		scenes.push(std::make_shared<Pausemenu>(this, _parameter));
		break;
	case eScene_CHARASELECT:
		scenes.push(std::make_shared<Charaselect>(this, _parameter));
		break;
	case eScene_LEVELSELECT:
		scenes.push(std::make_shared<LevelSelect>(this, _parameter));
		break;
	}
}