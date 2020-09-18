#ifndef _UI_H
#define _UI_H

#include "CastleManager.h"
#include "ItemManager.h"
#include "BuffManager.h"

class CastleManager;
class ItemManager;
class BuffManager;
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
	static const int MAX_DURABILTY = 100;		//メイン拠点最大体力
	static const int MAX_SABDURABILTY = 10;	//サブ拠点最大体力

	static const int PMOJI_X = 1550;			//文字のｘ
	static const int PMOJI_Y = 960;
	static const int PBAR_X = 1600;				//枠のｘ始点
	static const int PBAR_Y = 960;
	static const int PBAR_X1 = 1600;			//枠のｘ終点
	static const int PBAR_Y1 = 960;
	static const int PGAUGE_X = 1600;			//バーのｘ始点
	static const int PGAUGE_Y = 960;
	static const int PGAUGE_X1 = 1600;			//バーのｘ終点
	static const int PGAUGE_Y1 = 960;

	static const int SMOJI_X = 1550;			//文字のｘ
	static const int SMOJI_Y = 1000;
	static const int SBAR_X = 1600;				//枠のｘ始点
	static const int SBAR_Y = 1000;
	static const int SBAR_X1 = 1600;			//枠のｘ終点
	static const int SBAR_Y1 = 1000;
	static const int SGAUGE_X = 1600;			//バーのｘ始点
	static const int SGAUGE_Y = 1000;
	static const int SGAUGE_X1 = 1600;			//バーのｘ終点
	static const int SGAUGE_Y1 = 1000;

	const int MAX_BUFF = 15;				//バフゲージの最大数

	int percent;					//パーセント
	int CastleDurability;			//拠点の体力
	int pBuffPoint;					//pアイテムのゲージ上昇用
	int sBuffPoint;					//sアイテムのゲージ上昇用
	int pBuffLevel;					//pアイテム獲得時のバフレベル
	int sBuffLevel;					//sアイテム獲得時のバフレベル

public:
	void Get_CastleDurability();		//メイン拠点の体力UI
	void Get_BuffPoint();
	void Get_SubCastleDurability();		//サブ拠点の体力UI 
	void Update(CastleManager* _castlemanager, ItemManager* _itemmanager, BuffManager* _buffmanager);		//更新処理
	void Draw();						//描画処理
};

#endif 
