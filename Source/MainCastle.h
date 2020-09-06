#ifndef _MAINCASTLE_H
#define _MAINCASTLE_H

#include "BaseCastle.h"
#include "Define.h"
#include "SE.h"
/*-------------------------------------------------------------
オブジェクト名:	MainCastle
概要	      : 拠点
アクセス      :
継承クラス    : Object(オブジェクト)
呼ばれ先      :
詳細説明	  : 拠点
--------------------------------------------------------------*/

class EnemyManager;

class MainCastle:public BaseCastle{

private:

public:
	 MainCastle(int);

	 bool ClisionHit(float ox, float oy, float ow, float oh,
		  int pow, int num, bool attackFlg, bool activeFlg);

	 void Update(EnemyManager*);               //更新処理
	 void Draw();                              //描画処理

};

#endif //_MAINCASTLE_H