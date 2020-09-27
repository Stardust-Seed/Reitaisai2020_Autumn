#ifndef _GAMECLEAR_H
#define _GAMECLEAR_H

#include "BaseScene.h"

class GameClear final :public BaseScene {
public:
	GameClear(ISceneChanger* _sceneChanger, Parameter* _parameter);
	void Update();
	void Draw();
};

#endif // !_GAMECLEAR_H