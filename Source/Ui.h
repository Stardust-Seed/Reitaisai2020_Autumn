#ifndef _UI_H
#define _UI_H

#include "Castle.h"

static const int MAX_DURABILITY;

class UI
{
private:
	static const int HPBAR_X = 10;		
	static const int HPBAR_Y = 10;		
	static const int HPBAR_X1 = 10;
	static const int HPBAR_Y1 = 10;

	float percent;					//パーセント
	int CastleDurability;			//拠点の体力
	int Color;						//色

public:
	void Set_CastleDurability(int CastleDurability, int MAX_DURABILITY);
	void Set_EnemyiesRest(int);
	void PlayGuide();
};
#endif 
