#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager() {

}

//����������
void SceneManager::Init(GameResource* _gameRes) {
	nowScene = "";
}

//�I������
void SceneManager::Final() {
	//�o�^���Ă������V�[������ɂ���
	scenes.clear();
}

//�X�V����
void SceneManager::Update(GameResource* _gameRes) {
	stackScene.top()->Update(_gameRes);
}

//�`�揈��
void SceneManager::Draw(GameResource* _gameRes) {
	stackScene.top()->Draw(_gameRes);
}

//�V�[���؂�ւ�����
void SceneManager::SceneChange(std::string _nextSceneName, bool _isStack, bool _isBack,
	GameResource* _gameRes) {
	//���̃V�[�������݂̃V�[����
	nowScene = _nextSceneName;

	//��O�̃V�[���ɖ߂�
	if (_isBack) {
		stackScene.top()->Final();
		stackScene.pop();
		return;
	}

	//stackScene�̒��g��S�č폜����
	if (!_isStack) {
		while (!stackScene.empty()) {
			stackScene.pop();
		}
	}

	//���̃V�[�����擾����
	Scene* scene = GetScene(_nextSceneName);

	//�V�[������̏ꍇ�����I������
	if (scene == nullptr)exit(EXIT_FAILURE);

	//stackScene�Ɏ��̃V�[�����i�[����
	stackScene.push(scene);

	//���̃V�[��������������
	stackScene.top()->Init(_gameRes);
}

//�V�[����o�^
void SceneManager::SetScene(std::string _nextSceneName, Scene* _sceneClass) {
	scenes[_nextSceneName] = _sceneClass;
}

//�V�[�����擾
Scene* SceneManager::GetScene(std::string _nextSceneName)const {
	auto it = scenes.find(_nextSceneName);		//�w��L�[���擾

	//�w��̃L�[�����݂��Ȃ��ꍇ
	if (scenes.end() == it) {
		return nullptr;
	}
	//���݂����ꍇ
	else {
		return it->second;
	}
}