#ifndef _CASTLE_H
#define _CASTLE_H

#include "Object.h"

/*-------------------------------------------------------------
オブジェクト名:	Castle
概要	      : 拠点
アクセス      :
継承クラス    : Object(オブジェクト)
呼ばれ先      :
詳細説明	  : 拠点
--------------------------------------------------------------*/

class Castle:Object{

private:

	int Durability;	//耐久力

	bool isActive;	//拠点の生存フラグ

public:

	void EnemyHit(int _power);    //敵が衝突してきたら実行される関数

};

#endif //_CASTLE_H