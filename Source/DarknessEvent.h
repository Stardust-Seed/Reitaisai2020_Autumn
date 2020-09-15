#ifndef _DARKNESSEVENT_H
#define _DARKNESSEVENT_H

#include <DxLib.h>
#include "BaseEvent.h"

class DarknessEvent : public virtual BaseEvent {
private:
	static const int FREAM = 60; //フレーム数

	static const int MAX_DARKNESSTIME = 15 * FREAM;	//暗闇時間　秒 * フレーム数

	static const int MAX_OPACITY = 255;		//最大不透明度

	enum PHASE {
		PHASE_START = 0,	//開始フェーズ　不透明度をあげる
		PHASE_DARK = 1,		//維持フェーズ　不透明度を維持
		PHASE_END = 2		//終了フェーズ　不透明度を下げる
	};

	int darkCount;		//経過時間

	int nowPhase;		//現在のフェーズ

	int opacity;		//不透明度

	int darkImage;		//画像格納用

public:
	DarknessEvent();	//コンストラクタ

	~DarknessEvent();	//デストラクタ

	void Update();		//更新

	void Draw();		//描画
};


#endif // !_DARKNESSEVENT_H
