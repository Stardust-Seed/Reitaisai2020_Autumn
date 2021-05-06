#ifndef BULLET_H_
#define BULLET_H_

#include "Object.h"
#include "DxLib.h"
#include "Image.h"
#include "Direction.h"
#include "BasePlayer.h"

class BaseEnemy;
class EnemyManager;

//弾の管理
class Bullet :public virtual Object
{
private:

	const float PI = 3.141592654;

	//エネミーのポインタ変数
	BaseEnemy* baseEnemy;

	//エネミー管理のポインタ変数
	EnemyManager* enemyManager;

	//DXライブラリで定義されている構造体（中身はfloat型のx,y,z）
	//弾の位置
	VECTOR pos;

	//弾の進む方向
	eDirection bullet_Move;

	//発射されてるかどうか
	bool isActive;

	//攻撃力
	int power;

	//チャージゲージ
	int shotPower;

	//画像
	int bulletGraph;

	//画像回転
	float graphAngle;

public:
	//当たり判定
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);

	//コンストラクタ時に弾の発生位置と、進む方向を引数で持たせる
	Bullet(VECTOR& position, int pl_type,eDirection pl_direction, bool pl_attack,int pl_power,int shotpower);        //コンストラクタ
	~Bullet();       //デストラクタ
	void Draw();     //描画
	void Update(EnemyManager* _eManager,BasePlayer* _basePlayer);   //更新

	float Get_x() { return pos.x; }           //x座標ゲッター
	float Get_y() { return pos.y; }			  //y座標ゲッター
	float Get_width() { return width; }       //widthゲッター
	float Get_height() { return height; }     //heightゲッター
	int Get_power() { return power; }         //powerゲッター

	bool Get_isActive() { return isActive; } //弾が攻撃中かどうかのゲッター
	bool Get_isHit() { return isHit; }       //弾の当たり判定のゲッター

	void Set_isActive(bool _Active) { isActive = _Active; } //弾のアクティブのセッター

};

#endif // BULLET_H_