#ifndef _SUBCASTLE_H
#define _SUBCASTLE_H

#include "BaseCastle.h"

/*-------------------------------------------------------------
オブジェクト名:	SubCastle
概要	      : サブ拠点
アクセス      :
継承クラス    : BaseCastle
呼ばれ先      :
詳細説明	  : サブ拠点、破壊されたら敵増加
--------------------------------------------------------------*/

class EnemyManager;
class BaseEnemy;
class SubCastle :public BaseCastle {

private:
	int durability;	                    //耐久力
	int popEnemy;                       //追加分の敵の数
	bool hitFlg;                        //ヒットしたかのフラグ
	bool isActive;	                    //拠点の生存フラグ

public:
	SubCastle(int,int);
	//こっち使わない
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh)
	{
		return isActive;
	}
	bool ClisionHit(float ox, float oy, float ow, float oh, int pow, int num, bool attackFlg, bool activeFlg);

	void Update(EnemyManager*);    //更新処理
	void Draw();                   //描画処理

	void EnemyCastle();            //敵パラメータの設定処理

};

#endif //_SUBCASTLE_H