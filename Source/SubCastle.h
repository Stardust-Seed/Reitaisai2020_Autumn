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
class SubCastle :public virtual BaseCastle {

private:
	int posType;                   //サブ拠点の場所

public:
	SubCastle(int,int);

	void Update(EnemyManager*);    //更新処理
	void Draw();                   //描画処理
};

#endif //_SUBCASTLE_H