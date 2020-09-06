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
	int popEnemy;                       //追加分の敵の数

public:
	SubCastle(int,int);

	bool ClisionHit(float ox, float oy, float ow, float oh,
	     int pow, int num, bool attackFlg, bool activeFlg);

	void Update(EnemyManager*);    //更新処理
	void Draw();                   //描画処理

	void EnemyCastle();            //敵パラメータの設定処理

};

#endif //_SUBCASTLE_H