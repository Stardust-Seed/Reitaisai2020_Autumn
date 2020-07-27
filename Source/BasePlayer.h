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

class BasePlayer:public virtual Object {

protected:

	const float	PLAYER_SPOWNPOSX = 300;	//プレイヤーの初期位置_X
	const float	PLEYER_SPOWNPOSY = 348;	//プレイヤーの初期位置_Y

	int speed;		                //プレイヤーの移動速度
	int power;		                //プレイヤーの攻撃力
	int stanTime;	                //プレイヤーのスタンタイム
	int attackTime;                 //プレイヤーの攻撃間隔

	int PlayerPos;                  //プレイヤーのいる場所
	// 0 = 左         1 = 上        2 = 右         3 = 下

	int isMove;                     //プレイヤーの移動方向
	// 0 = 左へ移動   1 =上へ移動   2 = 右へ移動   3 = 下へ移動   4 = なし

	bool isDamage;                  //プレイヤーの被弾フラグ

	float x2;         //テスト用
	float y2;         //テスト用
	int Color;                      //テスト用のカラー

public:
	 virtual bool ClisionHit(float mx, float my, float mw, float mh,
		     float ox, float oy, float ow, float oh) = 0;
	 //m = my 自分   o = opnet 相手

	 virtual void Update();         //更新処理
	 virtual void Draw();           //描画処理
	 virtual void Move();           //移動処理
	 virtual void Move_UP();        //↑移動処理
	 virtual void Move_DOWN();      //↓移動処理
	 virtual void Move_LEFT();      //←移動処理
	 virtual void Move_RIGHT();     //→移動処理
	 virtual void All();            //プレイヤーの処理
	 virtual void Attack();         //攻撃処理

	 virtual void Set_x(int _x) { x = _x; }                        //セッター
	 virtual void Set_y(int _y) { y = _y; }                        //セッター
	 virtual void Set_width(int _width) { width = _width; }        //セッター
	 virtual void Set_height(int _height) { height = _height; }    //セッター

	 virtual int Get_x() { return x; }                             //ゲッター
	 virtual int Get_y() { return y; }                             //ゲッター
	 virtual int Get_width() { return width; }                     //ゲッター
	 virtual int Get_height() { return height; }                   //ゲッター

};

#endif //_BASEPLAYER_H