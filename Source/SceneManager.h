#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H

#include <stack>
#include <memory>
#include "BaseScene.h"
#include "ISceneChanger.h"
#include "GameResource.h"

//�V�[���Ǘ��N���X
class SceneManager final :public ISceneChanger {
private:
	Parameter parameter;								//�p�����[�^�[
	GameResource* gameRes;								//�Q�[�����\�[�X
	std::stack<std::shared_ptr<BaseScene>> scenes;		//�V�[��

	bool isChange;
	eScene nowScene;
	eScene frontScene;
public:
	SceneManager(GameResource* _gameRes);							//�R���X�g���N�^
	void Update();													//�X�V����
	void Draw();													//�`�揈��
	void SceneChange(eScene _nextScene, Parameter* _parameter,		//�V�[���؂�ւ�����
		const bool _isStack, const bool _isBack);

	eScene GetNowScene() { return nowScene; }						//���݂̃V�[�����擾
};

#endif // !_SCENEMANAGER_H