#ifndef _DARKNESSEVENT_H
#define _DARKNESSEVENT_H

#include <DxLib.h>
#include "BaseEvent.h"
#include "Define.h"


class DarknessEvent : public virtual BaseEvent {
private:

	static const int MAX_DARKNESSTIME = 15 * FRAME;	//暗闇時間　秒 * フレーム数

	static const int MAX_OPACITY = 255;		//最大不透明度

	enum PHASE {
		PHASE_START,	//開始フェーズ　不透明度をあげる
		PHASE_DARK,		//維持フェーズ　不透明度を維持
		PHASE_END		//終了フェーズ　不透明度を下げる
	};

	PHASE nowPhase;		//現在のフェーズ

	int darkCount;		//経過時間

	int opacity;		//不透明度

public:
	DarknessEvent();	//コンストラクタ

	~DarknessEvent();	//デストラクタ

	void Update();		//更新

	void Draw();		//描画
};


#endif // !_DARKNESSEVENT_H
