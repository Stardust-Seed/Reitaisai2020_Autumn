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

	const float	PLAYER_SPOWNPOSX = 392;	   //プレイヤーの初期位置_X
	const float	PLAYER_SPOWNPOSY = 348;	   //プレイヤーの初期位置_Y
	const float PLAYER_UPDOWNPOSX = 485;   //プレイヤーの上と下の位置X
	const float PLAYER_UPPOSY = 264;       //プレイヤーの上の位置Y
	const float PLAYER_DOWNPOSY = 456;     //プレイヤーの下の位置Y
	const float PLAYER_LEFTRIGHTPOS = 345; //プレイヤーの左と右の高さ
	const float PLAYER_LEFTPOS = 392;      //プレイヤーの左の位置
	const float PLAYER_RIGHTPOS = 584;     //プレイヤーの右の位置

	const int   MAX_SHOT = 10;             //プレイヤーの最大弾(仮)

	int speed;		                //プレイヤーの移動速度
	int power;		                //プレイヤーの攻撃力
	int stanTime;	                //プレイヤーのスタンタイム
	int AttackTime;                 //プレイヤーの攻撃間隔

	int PlayerPos;                  //プレイヤーのいる場所
	// 0 = 左         1 = 上        2 = 右         3 = 下

	int isMove;                     //プレイヤーの移動方向
	// 0 = 左へ移動   1 =上へ移動   2 = 右へ移動   3 = 下へ移動   4 = なし

	bool isMoveKey;                 //キー入力による移動かをチェックするフラグ。反対移動処理との重複を防ぐため
	bool isOps;                     //反対移動処理を起動するためのフラグ
	bool isOps_RUN;                 //反対移動処理を実行するためのフラグ
	bool isOps_UP;                  //上の反対に移動するためのフラグ
	bool isOps_DOWN;                //下の反対に移動するためのフラグ
	bool isOps_LEFT;                //左の反対に移動するためのフラグ
	bool isOps_RIGHT;               //右の反対に移動するためのフラグ
	bool isDamage;                  //プレイヤーの被弾フラグ

	class Shot {
	public:
		float x;       //弾のx座標
		float y;       //弾のy座標
		float width;   //弾の幅
		float height;  //弾の高さ
		float cx;      //弾の中心x
		float cy;      //弾の中心y
		float shot_gh; //グラフィックハンドル
		int flag;      //存在フラグ
	public:
		Shot();

		void Set_x(float _x) { x = _x; }                        //セッター
		void Set_y(float _y) { y = _y; }                        //セッター
		void Set_width(float _width) { width = _width; }        //セッター
		void Set_height(float _height) { height = _height; }    //セッター

		float Get_x() { return x; }          //x座標ゲッター
		float Get_y() { return y; }          //y座標ゲッター
		float Get_width() { return width; }  //widthゲッター
		float Get_height() { return height; }//heightゲッター
		//BasePlayer* BasePlayer;
	};
	Shot shot[10];

	//テスト用
	int x2;
	int y2;

public:
	 virtual bool ClisionHit(float mx, float my, float mw, float mh,
		     float ox, float oy, float ow, float oh) = 0;
	 //m = my 自分   o = opnet 相手

	 BasePlayer();                  //ベースプレイヤーのコンストラクタ

	 virtual void Update();         //更新処理
	 virtual void Draw();           //描画処理
	 virtual void Move();           //移動処理
	 virtual void Move_UP();        //↑移動処理
	 virtual void Move_DOWN();      //↓移動処理
	 virtual void Move_LEFT();      //←移動処理
	 virtual void Move_RIGHT();     //→移動処理
	 virtual void Move_OPS();       //反対移動処理:起動
	 virtual void Move_OPSRUN();    //反対移動処理:処理
	 virtual void Attack();         //攻撃処理

	  void Set_x(float _x) { x = _x; }                        //セッター
	  void Set_y(float _y) { y = _y; }                        //セッター
	  void Set_width(float _width) { width = _width; }        //セッター
	  void Set_height(float _height) { height = _height; }    //セッター

	  float Get_x() { return x; }                             //ゲッター
	  float Get_y() { return y; }                             //ゲッター
	  float Get_width() { return width; }                     //ゲッター
	  float Get_height() { return height; }                   //ゲッター

};

#endif //_BASEPLAYER_H