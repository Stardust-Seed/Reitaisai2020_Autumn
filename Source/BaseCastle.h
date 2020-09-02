#ifndef _BASECASTLE_H
#define _BASECASTLE_H

#include "Object.h"

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
	static const int MAX_DURABILITY;		//最大耐久力			

	int durability;		                    //拠点の体力

	bool isActive;		                    //拠点の生存フラグ

public:
	BaseCastle(int);                 //コンストラクタ

	virtual void Update(EnemyManager*) {} 			//更新処理
	virtual void Draw() {}			//描画処理

	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh) 
	{
		return isActive;
	}
	// m = my 自分   o = opnet 相手	//当たり判定処理

	//ゲッター
	bool GetIsActive() { return isActive; }

	int Get_Durability() { return durability; }

	float Get_X() { return x; }
	float Get_Y() { return y; }
	float Get_Width() { return width; }
	float Get_Height() { return height; }

	void Set_Durability(int);
	void Set_IsActive(bool);
};

#endif //_BASECASTLE_H_