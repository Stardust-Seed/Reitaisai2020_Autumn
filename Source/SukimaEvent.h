#ifndef _SUKIMAEVENT_H
#define _SUKIMAEVENT_H

#include <DxLib.h>
#include "BaseEvent.h"

class EnemyManager;

class SukimaEvent : public virtual BaseEvent {
private:
	static const int UP_X = 450;		//スキマの発生場所上
	static const int UP_Y = 150;		//スキマの発生場所上
	static const int DOWN_X = 450;	    //スキマの発生場所下
	static const int DOWN_Y = 650;	    //スキマの発生場所下
	static const int LEFT_X = 150;	    //スキマの発生場所左
	static const int LEFT_Y = 350;      //スキマの発生場所左
	static const int RIGHT_X = 750;	    //スキマの発生場所右
	static const int RIGHT_Y = 350;     //スキマの発生場所右

	//object継承してないので
	float x;
	float y;
	float width;
	float height;

	//ワープ先の場所
	float warpPosX;
	float warpPosY;

	bool isHit;
public:
	SukimaEvent();
	~SukimaEvent();
	void Update(EnemyManager*);		//更新
	void Draw();	            	//描画
	void Animation();               //アニメーション
	//当たり判定
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);
};

#endif // !_SUKIMAEVENT_H
