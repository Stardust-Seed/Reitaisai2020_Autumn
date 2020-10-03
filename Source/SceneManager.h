#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H

#include <stack>
#include <memory>
#include "BaseScene.h"
#include "ISceneChanger.h"

class SceneManager final :public ISceneChanger {
private:
	Parameter parameter;
	std::stack<std::shared_ptr<BaseScene>> scenes;

	bool isChange;
	eScene nowScene;
	eScene frontScene;
public:
	SceneManager();
	void Update();
	void Draw();
	void SceneChange(eScene _nextScene, Parameter* _parameter,
		const bool _isStack, const bool _isBack);

	eScene GetNowScene() { return nowScene; }
};

#endif // !_SCENEMANAGER_H