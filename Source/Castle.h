#ifndef _CASTLE_H
#define _CASTLE_H

#include "Object.h"
#include "Define.h"

/*-------------------------------------------------------------
オブジェクト名:	Castle
概要	      : 拠点
アクセス      :
継承クラス    : Object(オブジェクト)
呼ばれ先      :
詳細説明	  : 拠点
--------------------------------------------------------------*/

class EnemyManager;
class Castle:public virtual Object{

private:
	static const int MAX_DURABILITY;    //最大耐久力

	int durability;	                    //耐久力

	bool isActive;	                    //拠点の生存フラグ

public:
	 Castle();
	 //こっち使わない
	 bool ClisionHit(float mx, float my, float mw, float mh,
		 float ox, float oy, float ow, float oh) 
	 {
		 return isActive;
	 }
	 //m = my 自分   o = opnet 相手

	 //こっち使う
	 bool ClisionHit(float ox, float oy, float ow, float oh,int pow);

	 void Update(EnemyManager* enemy);               //更新処理
	 void Draw();                                    //描画処理

	 float Get_x() { return x; }                                            //ゲッター
	 float Get_y() { return y; }                                            //ゲッター
	 float Get_width() { return width; }                                    //ゲッター
	 float Get_height() { return height; }                                  //ゲッター
	 bool  Get_IsActive() { return isActive; }                              //ゲッター
	 int   Get_durability() { return durability; }                          //ゲッター
};

#endif //_CASTLE_H