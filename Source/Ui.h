#ifndef _UI_H
#define _UI_H

#include "CastleManager.h"
#include "ItemManager.h"
#include "BuffManager.h"
#include "BasePlayer.h"
#include "BulletManager.h"
#include "TimeLimit.h"

class CastleManager;
class ItemManager;
class BuffManager;
class BuletManager;
class BasePlayer;
class TimeLimit;

class UI
{
private:
	static const int HPMOJI_X = 20;				//文字のｘ
	static const int HPMOJI_Y = 25;				//文字のy
	static const int HP_X = 250;				//HPの数値x
	static const int HP_Y = 15;					//HPの数値y
	static const int HPBAR_X = 70;				//枠のｘ始点
	static const int HPBAR_Y = 50;		
	static const int HPBAR_X1 = 370;			//枠のｘ終点
	static const int HPBAR_Y1 = 80;
	static const int HPGAUGE_X = 70;			//バーのｘ始点
	static const int HPGAUGE_Y = 50;
	static const int HPGAUGE_X1 = 100;			//バーのｘ終点
	static const int HPGAUGE_Y1 = 80;	
	static const int REDGAUGE = 10;             //エネミーの最大攻撃力が一発殴ったら0になる値
	static const int MAX_DURABILTY = 100;		//メイン拠点最大体力
	static const int MAX_SABDURABILTY = 25;		//サブ拠点最大体
	

	static const int PMOJI_X = 1700;			//文字のｘ
	static const int PMOJI_Y = 800;
	static const int PMOJI_X1 = 1730;
	static const int PMOJI_Y1 = 750;
	static const int PBAR_X = 1700;				//枠のｘ始点
	static const int PBAR_Y = 1050;
	static const int PBAR_X1 = 1730;			//枠のｘ終点
	static const int PBAR_Y1 = 800;
	static const int PGAUGE_X = 1700;			//バーのｘ始点
	static const int PGAUGE_Y = 1050;
	static const int PGAUGE_X1 = 1730;			//バーのｘ終点
	static const int PGAUGE_Y1 = 1050;

	static const int SMOJI_X = 1800;			//文字のｘ
	static const int SMOJI_Y = 800;
	static const int SMOJI_X1 = 1830;
	static const int SMOJI_Y1 = 750;
	static const int SBAR_X = 1800;				//枠のｘ始点
	static const int SBAR_Y = 1050;
	static const int SBAR_X1 = 1830;			//枠のｘ終点
	static const int SBAR_Y1 = 800;
	static const int SGAUGE_X = 1800;			//バーのｘ始点
	static const int SGAUGE_Y = 1050;
	static const int SGAUGE_X1 = 1830;			//バーのｘ終点
	static const int SGAUGE_Y1 = 1050;

	const int MAX_BUFF = 15;					//バフゲージの最大数

	static const int SKILLBAR_X = 0;			//枠のｘ始点
	static const int SKILLBAR_Y = 160;
	static const int SKILLBAR_X1 = 0;			//枠のｘ終点
	static const int SKILLBAR_Y1 = 160;
	static const int SKILLGAUGE_X = 0;			//バーのｘ始点
	static const int SKILLGAUGE_Y = 160;
	static const int SKILLGAUGE_X1 = 0;			//バーのｘ終点
	static const int SKILLGAUGE_Y1 = 160;

	static const int CHARGEGAUGE_X = 25;        //チャージゲージの始点
	static const int CHARGEGAUGE_Y = 1000;
	static const int CHARGEGAUGE_X2 = 350;     //チャージゲージの終点
	static const int CHARGEGAUGE_Y2 = 1040;

	const int MAX_SAKUYATIME = 5;				//咲夜さんの時止め最大タイム
	const int MAX_FRANTIME = 3;					//フランさんの殲滅最大タイム

	int percent;					//パーセント
	int CastleDurability;			//拠点の体力
	int SubCastleDurability[5];		//拠点の数
	int castleNum;                  //設置できるサブ拠点の数
	int castleNumber;               //選択中の設置予定サブ拠点番号
	int i;
	
	int pBuffPoint;					//pアイテムのゲージ上昇用
	int sBuffPoint;					//sアイテムのゲージ上昇用
	int pBuffLevel;					//pアイテム獲得時のバフレベル
	int sBuffLevel;					//sアイテム獲得時のバフレベル
	int skillCount;					//スキル使用回数
	int skillClock;					//スキルの使用タイム
	int skillType;
	int hundredsTime;
	int tensTime;
	int onesTime;

	float pX;						//プレイヤーのx座標
	float pY;						//プレイヤーのy座標
	float castleX[5];				//拠点のx座標
	float castleY[5];				//拠点のy座標

	bool isActive[5];				//サブ拠点がActive状態であるか
	bool skillActive;				//スキルが発動してるか
	bool skillFran;					//フランさんのすきるが発動してるか

	int maxGauge;                   //最大ゲージ
	int chageGauge;                 //チャージゲージ
	int playerPower;                //キャラパワー


public:
	void Get_CastleDurability();		//メイン拠点の体力UI
	void Get_BuffPoint();				//アイテムポイントのUI
	void Get_SubCastleDurability();		//サブ拠点の体力UI 
	void AbilityUi();					//アビリティのUI
	void ChargeGage();                  //チャージゲージ
	void TimeLimitUi();					//タイムリミットUI
	void Update(GameResource* _gameRes);		//更新処理
	void Draw(GameResource* _gameRes);						//描画処理

};

#endif 
