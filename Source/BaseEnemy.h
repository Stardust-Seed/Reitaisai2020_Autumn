#ifndef _BASEENEMY_H
#define _BASEENEMY_H

#include "Object.h"

class Castle;
class BasePlayer;

/*-------------------------------------------------------------
オブジェクト名    BaseEnemy
概要    エネミーの元になるオブジェクト
アクセス
継承クラス    Object(オブジェクト)
呼ばれ先
詳細説明    Objectから継承した、エネミーの元となるエネミー
--------------------------------------------------------------*/

class BaseEnemy :public virtual Object {
protected:
	static const float ENEMY_SPAWNXLEFT;	//エネミーの初期位置X左
	static const float ENEMY_SPAWNYLEFT;	//エネミーの初期位置Y左
	static const float ENEMY_SPAWNXUP;		//エネミーの初期位置X上
	static const float ENEMY_SPAWNYUP;		//エネミーの初期位置Y上
	static const float ENEMY_SPAWNXRIGHT;	//エネミーの初期位置X右
	static const float ENEMY_SPAWNYRIGHT;	//エネミーの初期位置Y右
	static const float ENEMY_SPAWNXDOWN;	//エネミーの初期位置X下
	static const float ENEMY_SPAWNYDOWN;	//エネミーの初期位置Y下

	static const int DIRECTIONLEFT;		//左方向
	static const int DIRECTIONRIGHT;	//右方向
	static const int DIRECTIONUP;		//上方向
	static const int DIRECTIONDOWN;		//下方向

	float speed;		//エネミーの移動速度
	float power;		//エネミーの攻撃力
	int durability;		//エネミーの体力
	int direction;		//エネミーの進行方向

	bool isAttack;		//エネミーの攻撃フラグ
	bool isActive;		//エネミーの生存フラグ

public:
	BaseEnemy(){}
	virtual ~BaseEnemy(){}

	BaseEnemy(float _speed, float _power, int _durability, int _direction);
	virtual void Update(Castle* _castle, BasePlayer* _player) {}	//更新処理
	void Move();					//移動処理
	void SearchCastle(float _ox, float _oy, float _ow, float _oh);	//城の範囲内かサーチ
	void SearchPlayer(float _px, float _py, float _pw, float _ph);	//プレイヤーが攻撃範囲内にいるかサーチ
	void JudgeActive();		//アクティブかを判断する
	void AttackProc();		//攻撃中の時間処理

	void Set_X(float _x) { x = _x; }						//x座標を設定する
	void Set_Y(float _y) { y = _y; }						//y座標を設定する
	void Set_Width(float _width) { width = _width; }		//widthを設定する
	void Set_Height(float _height) { height = _height; }	//heightを設定する

	float Get_X() { return x; }				//x座標を取得する
	float Get_Y() { return y; }				//y座標を取得する
	float Get_Width() { return width; }		//widthを取得する
	float Get_Height() { return height; }	//heightを取得する
	float GetPower() { return power; }		//エネミーの攻撃力を取得する
	bool GetIsActive() { return isActive; }	//生存フラグを取得する
	bool GetIsAttack() { return isAttack; }	//アタックフラグを取得する
	
	virtual bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);
	// m = my 自分   o = opnet 相手	//当たり判定処理

	virtual void Draw() {}   //描画処理
};

#endif _BASEENEMY_HS