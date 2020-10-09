#ifndef _SUKIMAEVENT_H
#define _SUKIMAEVENT_H

#include "BaseEvent.h"
#include "Define.h"
#include "Direction.h"
#include "Image.h"
#include "SE.h"

class EnemyManager;
class BasePlayer;

class SukimaEvent : public virtual BaseEvent {
private:
	static const int UP_X = GAME_WIDTH  / 2;		     //スキマの発生場所上
	static const int UP_Y = GAME_HEIHGT / 2 - 460;		 //スキマの発生場所上

	static const int DOWN_X = GAME_WIDTH  / 2;	         //スキマの発生場所下
	static const int DOWN_Y = GAME_HEIHGT / 2 + 460;	 //スキマの発生場所下

	static const int LEFT_X = GAME_WIDTH  / 2 - 460;	 //スキマの発生場所左
	static const int LEFT_Y = GAME_HEIHGT / 2;           //スキマの発生場所左

	static const int RIGHT_X = GAME_WIDTH  / 2 + 460;    //スキマの発生場所右
	static const int RIGHT_Y = GAME_HEIHGT / 2;          //スキマの発生場所右

	//object継承してないので
	float x;
	float y;
	float width;
	float height;
	float addSize;

	//ワープ先の場所
	float warpPosX;
	float warpPosY;

	//当たり判定
	bool isHit;
	int hitNum;

	//スキマの場所
	int type;

	//自然消滅用カウント
	int deleteCnt;

	//時止め時用のフラグ

	bool sakuyaSkill;

	//アニメーション再生用
	bool popFlg;
	bool deleteFlg;
	bool animationFlg;
	int warpAnimationCnt;
	int popAnimationCnt;
	int animation[62] = { 4,0,0,0,0,0,1,1,1,1,1,
						  2,2,2,2,2,3,3,3,3,3,
		                  3,3,3,3,3,3,3,3,3,3,
		                  3,3,3,3,3,3,3,3,3,3,
				       	  3,3,3,3,3,2,2,2,2,2,
		                  1,1,1,1,1,0,0,0,0,0,4 };
public:
	SukimaEvent();
	~SukimaEvent();
	void Update(EnemyManager*,BasePlayer*);		//更新
	void Draw();	            	//描画
	void Animation();               //アニメーション
	//当たり判定
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);
};

#endif // !_SUKIMAEVENT_H
