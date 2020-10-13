#ifndef _BASE_PLAYER_H
#define _BASE_PLAYER_H

#include"Object.h"
#include"DxLib.h"
#include "FontHandle.h"

class BulletManager;
class BuffManager;
class EnemyManager;
class BaseEnemy;

enum PlayerType
{
	//キャラクター
	SAKUYA,     //咲夜
	FRAN        //フラン
};

//キャラクタースキルタイプ
enum AbilityType
{
	//キャラのスキルタイプ
	SAKUYA_Ability,         //咲夜のスキル
	FRAN_Ability            //フランのスキル
};

class BasePlayer :public virtual Object
{
	//弾管理のポインタ変数
	BulletManager* bulletManager;

	//エネミー管理のポインタ変数
	EnemyManager* enemyManager;

	//エネミーのポインタ変数
	BaseEnemy* baseEnemy;

	//キャラクター選択
	int playerType;


protected:
	const float PI = 3.141592654;

	const float PLAYER_SPOWNPOSX = 841;	    //プレイヤーの初期位置_X
	const float PLAYER_SPOWNPOSY = 516;	    //プレイヤーの初期位置_Y

	const float PLAYER_UPDOWNPOSX = 936;    //プレイヤーの上と下の位置X

	const float PLAYER_UPPOSY = 426;        //プレイヤーの上の位置Y
	const float PLAYER_DOWNPOSY = 606;      //プレイヤーの下の位置Y

	const float PLAYER_LEFTRIGHTPOS = 516;  //プレイヤーの左と右の高さ
	const float PLAYER_LEFTPOS = 841;       //プレイヤーの左の位置

	const float PLAYER_RIGHTPOS = 1026;     //プレイヤーの右の位置

	const int ANIMETION_MAX = 3;            //アニメーションの最大数
	const int ANIMETION_SPEED = 10;         //アニメーションのスピード

	//咲夜スキル用
	const int STOPTIME = 5;         //時止めスキルの時間
	int abilityTimer;               //スキル発動時間
	int countDown;                  //スキルタイマーのカウントダウンに使用

	//フランスキル用
	const int FRANTIME = 3;
	int franTimer;
	bool franAbility;

	int drawCount;                  //描画カウント
	double drawAngle;               //描画角度
	double drawZoom;                //描画拡大率

	int speed;		                //プレイヤーの移動速度
	int power;		                //プレイヤーの攻撃力
	int stanTime;	                //プレイヤーのスタンタイム
	int stanTime_stay;              //一度スタンしてから次にまたスタンするまでの時間
	int attackTime;                 //攻撃間隔
	int star01X;                    //スタンスター①のx座標
	int star01Y;                    //スタンスター①のy座標
	int star02X;                    //スタンスター②のx座標
	int star02Y;                    //スタンスター②のy座標

	int graphNo;                    //画像番号                0,1:咲夜 2,3:フラン
	int sakuyaAnim[4] = {2,2,3,3 }; //咲夜アニメーション順番
	int franAnim[4] = { 0,0,1,1 };  //フランアニメーション番号
	int animNo;                     //アニメーション番号
	int animWait;                   //アニメーション待機時間

	bool animLR;                    //アニメーションの左右 true :← false :→

	bool isAbility;                 //スキルが発動している状態かどうか
	int  abilityCount;              //スキル回数
	int  bulletCount;               //弾のカウント

	int playerDirection;                  //プレイヤーの向き
	// 0 = 左         1 = 上        2 = 右         3 = 下

	bool isMove;                   //現在移動中のフラグ

	bool isDraw;                    //プレイヤー描画フラグ
	bool isAttack;                  //攻撃フラグ
	bool isStan;                    //スタン中かどうかのフラグ
	bool isStan_Next;               //スタンが起こる状態かどうかのフラグ

public:

	//DXライブラリで定義されている構造体
//中身はfloat型の(x,y,z)
	VECTOR pos;                     //プレイヤーの座標

	VECTOR vPos;                    //プレイヤーを移動させるため

	//当たり判定
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);
	BasePlayer() {}
	BasePlayer( int _pType);		   //コンストラクタ
	~BasePlayer();         //デストラクタ
	void Draw();           //描画処理
	void Draw_Arow();      //矢印描画
	void Draw_Ability();   //スキルエフェクト描画

	//更新処理
	void Update(EnemyManager* _eManager,BuffManager* _bManager);

	void Move();           //移動処理
	void Move_UP();        //↑移動処理
	void Move_DOWN();      //↓移動処理
	void Move_LEFT();      //←移動処理
	void Move_RIGHT();     //→移動処理
	void Attack();         //攻撃処理
	void Animation();      //アニメーション
	void onAbility();      //スキル発動処理
	void CharaAbility();   //スキル処理

	//スタン処理
	void Stan(BuffManager* _bManager);           

	void Set_x(float _x) { pos.x = _x; }                    //セッター
	void Set_y(float _y) { pos.y = _y; }                    //セッター
	void Set_width(float _width) { width = _width; }        //セッター
	void Set_height(float _height) { height = _height; }    //セッター
	void Set_isAbility(bool _isAbility) { isAbility = _isAbility; } //スキルのActiveセッター
	void Set_abilityCount(int _abilityCount) { abilityCount = _abilityCount; }  //スキル回数のセッター      

	float Get_x() { return pos.x; }                         //x座標ゲッター
	float Get_y() { return pos.y; }                         //y座標ゲッター
	float Get_cx() { return pos.x + 24; }                   //cx座標ゲッター
	float Get_cy() { return pos.y + 24; }                   //cy座標ゲッター
	float Get_width() { return width; }                     //widthゲッター
	float Get_height() { return height; }                   //heightゲッター

	int  Get_power() { return power; }                      //攻撃力ゲッター

	bool Get_isStan() { return isStan; }                    //スタン状態ゲッター
	bool Get_isAbility() { return isAbility; }              //スキルのActiveのゲッター
	
	void SetBulletManager(BulletManager* bullet) { bulletManager = bullet; }//bulletManagerのアドレスを取得

	int Get_AbilityType() { return playerType; }            //スキルタイプのゲッター

	bool Get_FranAbility(){ return franAbility; }          //フランアビリティのゲッター
	int Get_AbilityCount() { return abilityCount; }         //スキル回数のゲッター
	int Get_AbilityClock() { return abilityTimer; }        //スキル時間のゲッター
};


#endif _BASE_PLAYER_H_