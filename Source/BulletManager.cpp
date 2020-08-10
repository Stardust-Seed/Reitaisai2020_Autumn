#include"DxLib.h"
#include"Bullet.h"
#include"BulletManager.h"

//コンストラクタ
BulletManager::BulletManager()
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		//NULLを入れる事で、一斉にdeleteする時に
		//NULLが入ったポインタは無視されるためエラーがなくなる
		bullet[i] = NULL;
	}

}
//デストラクタ
BulletManager::~BulletManager()
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		delete bullet[i];
	}

}
//弾を発射する関数
void BulletManager::Shot(VECTOR& pos, int pl_pos, bool pl_attack)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		//NULLの物を探して,動的確保するのみ
		if (bullet[i] == NULL)
		{
			bullet[i] = new Bullet(pos, pl_pos, pl_attack);
			break;
		}
	}
}
//更新処理
void BulletManager::Update()
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		//NULLでない場合,BulletのUpdate関数を行う
		if (bullet[i] != NULL)
		{
			bullet[i]->Update();

			//弾が画面外に出ていた場合か弾が敵に当たった場合
			if (bullet[i]->Get_Flag() == false || bullet[i]->Get_Hit() == true)
			{
				//削除してNULLを入れて、また使えるようにする
				delete bullet[i];
				bullet[i] = NULL;
			}
		}
	}

}
//描画処理
void BulletManager::Draw()
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		//NULLでない場合,BulletのDraw関数を行う
		if (bullet[i] != NULL)
		{
			bullet[i]->Draw();

		}
	}

}