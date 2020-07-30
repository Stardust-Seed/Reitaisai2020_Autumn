#ifndef _OPTION_H
#define _OPTION_H

#include "BaseScene.h"

class Option :public BaseScene {
private:
	static const float BGMBAR_WIDTH;
	static const float BGMBAR_HEIGHT;
	static const float BGMBAR_INTERVAL;
	static const int BGMBAR_MAXNUM;

	static const float SEBAR_WIDTH;
	static const float SEBAR_HEIGHT;
	static const float SEBAR_INTERVAL;
	static const int SEBAR_MAXNUM;
public:
	Option();
	void Update();
	void Draw();
};

#endif // !_OPTION_H