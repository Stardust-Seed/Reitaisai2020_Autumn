#ifndef BULLET_MANAGER_H_
#define BULLET_MANAGER_H_

#include"Object.h"

//弾クラス
class Bullet;

#define MAX_BULLET 10   //弾の最大

class BulletManager
{
	Bullet* bullet[MAX_BULLET];  //適当に最大弾は10発

public:
	BulletManager();    //コンストラクタ
	~BulletManager();   //デストラクタ

	//弾を発射する関数
	void Shot(VECTOR& pos, int pl_pos, bool pl_attack);
	//更新
	void Update();
	//描画
	void Draw();
};

#endif // BULLET_MANAGER_H_