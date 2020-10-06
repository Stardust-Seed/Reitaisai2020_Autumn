#ifndef _BASECASTLE_H
#define _BASECASTLE_H

#include "Object.h"
#include "Direction.h"
#include "Define.h"
#include "Image.h"
#include "SE.h"
/*-------------------------------------------------------------
オブジェクト名    BaseCastle
概要    拠点の元になるオブジェクト
アクセス
継承クラス    Object(オブジェクト)
呼ばれ先
詳細説明    Objectから継承した、拠点の元
--------------------------------------------------------------*/

class EnemyManager;

class BaseCastle :public Object {
protected:
	int maxDurabiliy;		                //最大耐久力			

	int durability;		                    //拠点の体力
	eDirection direction;
	bool isActive;		                    //拠点の生存フラグ
	bool dyingFlg;                          //瀕死フラグ
	float addPosX;                   //追加の座標X(表示部分のみ)  
	float addPosY;                   //追加の座標Y(表示部分のみ)  

public:
	BaseCastle(int);                        //コンストラクタ

	virtual void Update(EnemyManager*) {} 	//更新処理
	virtual void Draw() {}		        	//描画処理

	//こっちは使わない
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh) {
		return false;
	}
	// m = my 自分   o = opnet 相手	//当たり判定処理

	//こっち使う
	bool ClisionHit(float ox, float oy, float ow, float oh,
		int pow, int num, bool attackFlg, bool activeFlg);

	//ゲッター
	//拠点関連
	int   Get_Durability() { return durability; }

	bool  GetIsActive()    { return isActive; }

	float Get_X() { return x; }
	float Get_Y() { return y; }
	float Get_Width() { return width; }
	float Get_Height() { return height; }
	float Get_AddPosX() { return addPosX; };		//幅を受け取る
	float Get_AddPosY() { return addPosY; };	    //高さを受け取る

	eDirection Get_CastleDirection() { return direction; }
};

#endif //_BASECASTLE_H_