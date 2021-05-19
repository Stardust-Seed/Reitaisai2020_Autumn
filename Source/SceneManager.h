#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H

#include <unordered_map>
#include <string>
#include <stack>
#include "GameResource.h"

class Scene;

//�V�[���Ǘ��N���X
class SceneManager final {
private:
	std::unordered_map <std::string, Scene*> scenes;	//�o�^�����V�[��
	std::stack<Scene*> stackScene;						//���s����V�[��

	std::string nowScene;								//���݂̃V�[��

	Scene* GetScene(std::string _sceneName)const;		//�V�[�����擾����
public:
	SceneManager();										//�R���X�g���N�^
	void Init(GameResource* _gameRes);					//����������
	void Final();										//�I������
	void Update(GameResource* _gameRes);				//�X�V����
	void Draw(GameResource* _gameRes);					//�`�揈��

	void SetScene(std::string _sceneName, Scene* _sceneClass);					//�V�[����o�^����
	void SceneChange(std::string _nextSceneName, bool _isStack, bool _isBack,
		GameResource* _gameRes);												//�V�[���؂�ւ�����

	std::string GetNowScene() { return nowScene; }		//���݂̃V�[�����擾����
};

#endif // !_SCENEMANAGER_H