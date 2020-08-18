#ifndef _BASE_PLAYER_H
#define _BASE_PLAYER_H

#include"Object.h"
#include"DxLib.h"

class BulletManager;
class EnemyManager;
class BaseEnemy;

class BasePlayer :public Object
{
	//弾管理のポインタ変数
	BulletManager* bulletManager;

	//エネミー管理のポインタ変数
	EnemyManager* enemyManager;

	//エネミーのポインタ変数
	BaseEnemy* baseEnemy;

private:
	const float PLAYER_SPOWNPOSX = 300;	    //プレイヤーの初期位置_X
	const float PLAYER_SPOWNPOSY = 356;	    //プレイヤーの初期位置_Y

	const float PLAYER_UPDOWNPOSX = 485;    //プレイヤーの上と下の位置X

	const float PLAYER_UPPOSY = 264;    //プレイヤーの上の位置Y
	const float PLAYER_DOWNPOSY = 456;      //プレイヤーの下の位置Y

	const float PLAYER_LEFTRIGHTPOS = 345;  //プレイヤーの左と右の高さ
	const float PLAYER_LEFTPOS = 392;       //プレイヤーの左の位置

	const float PLAYER_RIGHTPOS = 584;      //プレイヤーの右の位置

	//DXライブラリで定義されている構造体
	//中身はfloat型の(x,y,z)
	VECTOR pos;                     //プレイヤーの座標

	VECTOR vPos;                    //プレイヤーを移動させるため

	int speed;		                //プレイヤーの移動速度
	int power;		                //プレイヤーの攻撃力
	int stanTime;	                //プレイヤーのスタンタイム
	int stanTime_stay;              //一度スタンしてから次にまたスタンするまでの時間
	int AttackTime;                 //攻撃間隔

	float width;
	float height;

	int PlayerPos;                  //プレイヤーのいる場所
	// 0 = 左         1 = 上        2 = 右         3 = 下

	int isMove;						//プレイヤーの移動の管理
	// 0 = 左へ移動   1 =上へ移動   2 = 右へ移動   3 = 下へ移動   4 = なし

	int Now_Move;                   //現在移動中のフラグ

	bool isMoveKey;                 //キー入力による移動かをチェックするフラグ。反対移動処理との重複を防ぐため
	bool isOps;                     //反対移動処理を起動するためのフラグ
	bool isOps_RUN;                 //反対移動処理を実行するためのフラグ
	bool isOps_UP;                  //上の反対に移動するためのフラグ
	bool isOps_DOWN;                //下の反対に移動するためのフラグ
	bool isOps_LEFT;                //左の反対に移動するためのフラグ
	bool isOps_RIGHT;               //右の反対に移動するためのフラグ
	bool isDamage;                  //プレイヤーの被弾フラグ
	bool isAttack;                  //攻撃フラグ
	bool isStan;                    //スタン中かどうかのフラグ
	bool isStan_Next;               //スタンが起こる状態かどうかのフラグ
public:
	//当たり判定
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);

	BasePlayer();		   //コンストラクタ
	~BasePlayer();         //デストラクタ
	void Draw();           //描画処理

	//更新処理
	void Update(EnemyManager* _eManager);

	void Move();           //移動処理
	void Move_UP();        //↑移動処理
	void Move_DOWN();      //↓移動処理
	void Move_LEFT();      //←移動処理
	void Move_RIGHT();     //→移動処理
	void Move_OPS();       //反対移動処理:起動
	void Move_OPSRUN();    //反対移動処理:処理
	void Attack();         //攻撃処理

	//スタン処理
	void Stan();           

	void Set_x(float _x) { pos.x = _x; }                        //セッター
	void Set_y(float _y) { pos.y = _y; }                        //セッター
	void Set_width(float _width) { width = _width; }        //セッター
	void Set_height(float _height) { height = _height; }    //セッター

	float Get_x() { return pos.x; }                         //x座標ゲッター
	float Get_y() { return pos.y; }                         //y座標ゲッター
	float Get_width() { return width; }                     //widthゲッター
	float Get_height() { return height; }                   //heightゲッター

	int  Get_power() { return power; }        //攻撃力ゲッター

	bool Get_isStan() { return isStan; }                    //スタン状態ゲッター

	//bulletManagerのアドレスを取得
	void SetBulletManager(BulletManager* bullet) { bulletManager = bullet; }

	//EnemyManagerのアドレスを取得
	//void SetEnemyManager(EnemyManager* eManager) { enemyManager = eManager; }

};


#endif _BASE_PLAYER_H_