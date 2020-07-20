#ifndef _BASEENEMY_H
#define _BASEENEMY_H
#include "Object.h"

/*-------------------------------------------------------------
オブジェクト名    BaseEnemy
概要    エネミーの元になるオブジェクト
アクセス
継承クラス    Object(オブジェクト)
呼ばれ先
詳細説明    Objectから継承した、エネミーの元となるエネミー
--------------------------------------------------------------*/

class BaseEnemy :Object {
	
protected:
	const float ENEMY_SPAWNXLEFT;	//エネミーの初期位置X左
	const float ENEMY_SPAWNYLEFT;	//エネミーの初期位置Y左
	const float ENEMY_SPAWNXUP;		//エネミーの初期位置X上
	const float ENEMY_SPAWNYUP;		//エネミーの初期位置Y上
	const float ENEMY_SPAWNXRIGHT;	//エネミーの初期位置X右
	const float ENEMY_SPAWNYRIGHT;	//エネミーの初期位置Y右
	const float ENEMY_SPAWNXDOWN;	//エネミーの初期位置X下
	const float ENEMY_SPAWNYDOWN;	//エネミーの初期位置Y下

	float speed;		//エネミーの移動速度
	float power;		//エネミーの攻撃力
	float dulability;	//エネミーの体力
	float direction;	//エネミーの進行方向

	bool isAttack;		//エネミーの攻撃フラグ
	bool isActive;		//エネミーの生存フラグ

public:
	virtual void Updata();		//更新処理
	virtual void Move();		//移動処理
	virtual void Tackle();		//拠点やプレイヤーに対する攻撃処理
	virtual void SearchPlayer();//プレイヤーが攻撃範囲内にいるかサーチ
	virtual void JudgeActive();	//アクティブかを判断する

	virtual int GetPower();		//エネミーの攻撃力取得

	virtual bool GetisAttack();	//アタックフラグの取得
	

	virtual bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh) = 0;
	// m = my 自分   o = opnet 相手	//当たり判定処理

	virtual void Draw();   //描画処理

};

#endif _BASEENEMY_H