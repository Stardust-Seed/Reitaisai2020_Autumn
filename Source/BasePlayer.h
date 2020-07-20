#ifndef _BASEPLAYER_H
#define _BASEPLAYER_H

#include "Object.h"

/*-------------------------------------------------------------
オブジェクト名:	BasePlayer
概要	      : プレイヤーの元になるオブジェクト
アクセス      :
継承クラス	  : Object(オブジェクト)
呼ばれ先      :
詳細説明	  : Objectから継承した、プレイヤーの元となるプレイヤー
--------------------------------------------------------------*/

class BasePlayer:Object{

protected:

	const float	PLAYER_SPOWNPOSX;	//プレイヤーの初期位置_X
	const float	PLEYER_SPOWNPOSY;	//プレイヤーの初期位置_Y

	int speed;		                //プレイヤーの移動速度
	int power;		                //プレイヤーの攻撃力
	int stanTime;	                //プレイヤーのスタンタイム
	int attackTime;                 //プレイヤーの攻撃間隔

	bool isDamage;                  //プレイヤーの被弾フラグ

public:

	 virtual void Move();           //移動処理

	 virtual void Attack();         //攻撃処理

};

#endif //_BASEPLAYER_H