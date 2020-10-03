#ifndef BULLET_MANAGER_H_
#define BULLET_MANAGER_H_

#include"Object.h"

//弾クラス
class Bullet;
class EnemyManager;

class BulletManager
{
	static const int MAX_BULLET = 50;  //弾の最大

	Bullet* bullet[MAX_BULLET];  //適当に最大弾は10発

	//エネミー管理のポインタ変数
	EnemyManager* enemyManager;

private:
	int activeBullet;   //Activeな弾の数
public:
	BulletManager();    //コンストラクタ
	~BulletManager();   //デストラクタ

	//弾を発射する関数
	void Shot(VECTOR& pos, int pl_pos, bool pl_attack);
	//更新
	void Update(EnemyManager* _enemyManager);
	//描画
	void Draw();

	bool Get_IsActive(int i); //弾が攻撃中かどうかのゲッター
	bool Get_IsHit(int i);    //弾が当たったかどうかのゲッター

	float Get_X(int i);       //弾のx座標ゲッター
	float Get_Y(int i);       //弾のy座標ゲッター
	float Get_Width(int i);   //弾のwidth座標ゲッター
	float Get_Height(int i);  //弾のheight座標ゲッター

	int Get_ActiveBullet();   //Activeな弾のゲッター
	int Get_MaxBullet();      //弾の最大数のゲッター

	void Set_isActive(int, bool);//弾のActiveのセッター
};

#endif // BULLET_MANAGER_H_