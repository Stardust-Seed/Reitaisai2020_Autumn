#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H

#include <stack>
#include <memory>
#include "BaseScene.h"
#include "ISceneChanger.h"

class SceneManager final :public ISceneChanger {
private:
	std::stack<std::shared_ptr<BaseScene>> scenes;
public:
	SceneManager();
	void Update();
	void Draw();
	void SceneChange(eScene _nextScene, const bool _isStack, const bool _isBack);
};

#endif // !_SCENEMANAGER_H