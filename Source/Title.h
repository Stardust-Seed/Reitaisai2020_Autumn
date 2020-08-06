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
	void Update();				//更新処理
	void Draw();				//描画処理
	void Move();                //移動処理
};

#endif //TITLE_H_