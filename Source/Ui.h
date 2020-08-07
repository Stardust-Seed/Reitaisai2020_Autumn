#ifndef _UI_H
#define _UI_H

#include "Castle.h"

class UI:public virtual Castle
{
private:
	static const int HPBAR_X = 10;		
	static const int HPBAR_Y = 10;		
	static const int HPBAR_X1 = 10;
	static const int HPBAR_Y1 = 10;
	static const int MAX_DURABILTY = 100;

	int percent;					//パーセント
	int CastleDurability;			//拠点の体力
	int Color;						//色

public:
	void Set_CastleDurability();		//拠点の体力を受け取る
	void Set_EnemyiesRest(int);			//コメント考えます
	void PlayGuide();					//プレイヤーのガイド
	void Update(Castle* _castle);		//更新処理
	void Draw();						//描画処理
};
#endif 
