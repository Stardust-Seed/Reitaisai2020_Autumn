#ifndef BULLET_H_
#define BULLET_H_

#include "Object.h"

class BaseEnemy;
class EnemyManager;

//弾の管理
class Bullet :public virtual Object
{
private:

	//エネミーのポインタ変数
	BaseEnemy* baseEnemy;

	//エネミー管理のポインタ変数
	EnemyManager* enemyManager;

	//DXライブラリで定義されている構造体（中身はfloat型のx,y,z）
	//弾の位置
	VECTOR pos;

	//弾の進む方向
	int Bullet_Move;

	//発射されてるかどうか
	bool isActive;

	//画像
	int gh;

	//テスト用カラー
	int Cr;
public:
	//当たり判定
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);

	//コンストラクタ時に弾の発生位置と、進む方向を引数で持たせる
	Bullet(VECTOR& position, int pl_pos, bool pl_attack);        //コンストラクタ
	~Bullet();       //デストラクタ
	void Draw();     //描画
	void Update(EnemyManager* _eManager);   //更新

	float Get_x() { return pos.x; }           //x座標ゲッター
	float Get_y() { return pos.y; }			  //y座標ゲッター
	float Get_width() { return width; }       //widthゲッター
	float Get_height() { return height; }     //heightゲッター

	bool Get_isActive() { return isActive; } //弾が攻撃中かどうかのゲッター
	bool Get_isHit() { return isHit; }          //弾が当たったかどうかのゲッター
};

#endif // BULLET_H_