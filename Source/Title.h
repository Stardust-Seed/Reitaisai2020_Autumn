#ifndef _TITLE_H_
#define _TITLE_H_

#include "BaseScene.h"
#include "Define.h"
#include "FontHandle.h"
#include "SE.h"


class Title final :public BaseScene {
private:
	float deg, rad;
	float o;
	int textSpeed[3];
	int cnt;
public:
	Title(ISceneChanger* _sceneChanger);
	~Title() = default;
	void Update();				//XVˆ—
	void Draw();				//•`‰æˆ—
	void Move();                //ˆÚ“®ˆ—
};

#endif //TITLE_H_