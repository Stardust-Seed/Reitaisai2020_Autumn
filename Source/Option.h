#ifndef _OPTION_H
#define _OPTION_H

#include "BaseScene.h"

enum SelectOptionType {
	select_BGM,
	select_SE
};

class Option :public BaseScene {
private:
	static const float BGMBAR_WIDTH;
	static const float BGMBAR_HEIGHT;
	static const float BGMBAR_INTERVAL;
	static const int BGM_MAXVOLUME;

	static const float SEBAR_WIDTH;
	static const float SEBAR_HEIGHT;
	static const float SEBAR_INTERVAL;
	static const int SE_MAXVOLUME;

	static const float SELECTBAR_X1;
	static const float SELECTBAR_X2;
	static const float SELECTBAR_YBGM;
	static const float SELECTBAR_YSE;

	static const float UIAREA_X1;
	static const float UIAREA_X2;
	static const float UIAREA_Y1BGM;
	static const float UIAREA_Y2BGM;
	static const float UIAREA_Y1SE;
	static const float UIAREA_Y2SE;

	static const int STRING_XBGM;
	static const int STRING_YBGM;
	static const int STRING_XSE;
	static const int STRING_YSE;

	int bgmVolume;	//BGM�̉���
	int seVolume;	//SE�̉���

	SelectOptionType selectType;	//���ݑI�����Ă�^�C�v
public:
	Option();
	void Update();
	void Draw();
};

#endif // !_OPTION_H