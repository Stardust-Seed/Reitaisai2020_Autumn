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

	 virtual bool ClisionHit(float mx, float my, float mw, float mh,
		     float ox, float oy, float ow, float oh) = 0;
	 //m = my 自分   o = opnet 相手

	 virtual void Update();                //更新処理
	 virtual void Draw();                  //描画処理
	 virtual void EnemyHit(int _power);    //敵が衝突してきたら実行される関数

};

#endif //_CASTLE_H