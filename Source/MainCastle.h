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
	int durability;	                    //耐久力

	bool hitFlg;                        //ヒットしたかのフラグ
	bool isActive;	                    //拠点の生存フラグ

public:
	 MainCastle(int);
	 //こっち使わない
	 bool ClisionHit(float mx, float my, float mw, float mh,
		 float ox, float oy, float ow, float oh) 
	 {
		 return isActive;
	 }
	 //m = my 自分   o = opnet 相手

	 //こっち使う
	 bool ClisionHit(float, float, float, float,int,int, bool,bool);

	 void Update(EnemyManager*);               //更新処理
	 void Draw();                              //描画処理

};

#endif //_MAINCASTLE_H