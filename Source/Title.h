#ifndef _TITLE_H_
#define _TITLE_H_

#include "BaseScene.h"
#include "Define.h"
#include "FontHandle.h"

class Title :public virtual BaseScene {

private:

	float deg, rad;
	float o;
	int textSpeed[3];
	int cnt;
	float w;

public:
	Title();
	void Update();				//XVˆ—
	void Draw();				//•`‰æˆ—
	void Move();                //ˆÚ“®ˆ—
};

#endif //TITLE_H_