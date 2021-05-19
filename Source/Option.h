#ifndef _OPTION_H
#define _OPTION_H

#include "Scene.h"

enum SelectOptionType {
	select_BGM,
	select_SE
};

class Option :public Scene {
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

	static const int BUF_SIZE;
	static const int CONFIGFILE_NUM;

	int bgmVolume;	//BGMの音量
	int seVolume;	//SEの音量

	int bColor;
	int sColor;

	int boxColorB;
	int boxColorS;

	int cNum[2] = {0,0};

	SelectOptionType selectType;	//現在選択してるタイプ
public:
	Option();
	void Init(GameResource* _gameRes);
	void Update(GameResource* _gameRes);
	void Draw(GameResource* _gameRes);
};

#endif // !_OPTION_H