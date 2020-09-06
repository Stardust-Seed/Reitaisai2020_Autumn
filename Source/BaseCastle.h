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

	//敵に送る占領地点から出現する敵のパラメータ
	float enemySpeed;                       //敵のスピード
	float enemyPower;                       //敵のパワー
	int enemyDurability;                    //敵の体力
	int enemyDirection;                     //敵の方向

public:
	BaseCastle(int);                        //コンストラクタ

	virtual void Update(EnemyManager*) {} 	//更新処理
	virtual void Draw() {}		        	//描画処理

	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh) 
	{
		return isActive;
	}
	// m = my 自分   o = opnet 相手	//当たり判定処理

	//ゲッター
	//拠点関連
	int   Get_Durability() { return durability; }

	bool  GetIsActive()    { return isActive; }

	float Get_X() { return x; }
	float Get_Y() { return y; }
	float Get_Width() { return width; }
	float Get_Height() { return height; }

	//敵パラメータ関連
	float Get_EnemySpeed() { return enemySpeed; }
	float Get_EnemyPower() { return enemyPower; }
	int Get_EnemyDurability() { return enemyDurability; }
	int Get_EnemyDirection() { return enemyDirection; }

	//セッター
	//拠点関連
	void Set_Durability(int _durability) { durability = _durability; }
	void Set_IsActive(bool _flg) { isActive = _flg; }

	//敵パラメータ関連
	void Set_EnemySpeed(float _speed) { enemySpeed = _speed; }
	void Set_EnemyPower(float _power) { enemyPower = _power; }
	void Set_EnemyDurability(int _durability) { enemyDurability = _durability; }
	void Set_EnemyDirection(int _direction) { enemyDirection = _direction; }
};

#endif //_BASECASTLE_H_