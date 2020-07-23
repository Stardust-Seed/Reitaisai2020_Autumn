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
	int dulability;		//エネミーの体力
	int direction;		//エネミーの進行方向

	bool isAttack;		//エネミーの攻撃フラグ
	bool isActive;		//エネミーの生存フラグ

public:
	BaseEnemy();
	virtual void Update() {}		//更新処理
	void Move();					//移動処理
	virtual void Tackle() {}		//拠点やプレイヤーに対する攻撃処理
	virtual void SearchPlayer() {}	//プレイヤーが攻撃範囲内にいるかサーチ
	virtual void JudgeActive();		//アクティブかを判断する

	void Set_X(int _x) { x = _x; }						//x座標を設定する
	void Set_Y(int _y) { y = _y; }						//y座標を設定する
	void Set_Width(int _width) { width = _width; }		//widthを設定する
	void Set_Height(int _height) { height = _height; }	//heightを設定する

	int Get_X() { return x; }				//x座標を取得する
	int Get_Y() { return y; }				//y座標を取得する
	int Get_Width() { return width; }		//widthを取得する
	int Get_Height() { return height; }		//heightを取得する
	int GetPower() { return power; }		//エネミーの攻撃力を取得する
	bool GetIsAttack() { return isAttack; }	//アタックフラグを取得する
	

	virtual bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);
	// m = my 自分   o = opnet 相手	//当たり判定処理

	virtual void Draw() {}   //描画処理

};

#endif _BASEENEMY_HS