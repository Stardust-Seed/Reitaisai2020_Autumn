#ifndef _UI_H
#define _UI_H

#include "CastleManager.h"

class CastleManager;
class UI
{
private:
	static const int HPMOJI_X = 0;				//文字のｘ
	static const int HPMOJI_Y = 10;				
	static const int HPBAR_X = 50;				//枠のｘ始点
	static const int HPBAR_Y = 10;		
	static const int HPBAR_X1 = 50;				//枠のｘ終点
	static const int HPBAR_Y1 = 10;
	static const int HPGAUGE_X = 50;			//バーのｘ始点
	static const int HPGAUGE_Y = 10;
	static const int HPGAUGE_X1 = 50;			//バーのｘ終点
	static const int HPGAUGE_Y1 = 10;	
	static const int MAX_DURABILTY = 100;		//拠点最大体力

	int percent;					//パーセント
	int CastleDurability;			//拠点の体力
	int Color;						//色

public:
	void Get_CastleDurability();		//拠点の体力を受け取る
	void PlayGuide();					//プレイヤーのガイド
	void Update(CastleManager* _castlemanager);		//更新処理
	void Draw();						//描画処理
};

#endif 
