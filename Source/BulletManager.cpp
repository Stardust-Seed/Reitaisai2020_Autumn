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

	activeBullet = 0;  //最初はアクティブな弾はない

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
			activeBullet++;
			break;
		}
	}
}
//更新処理
void BulletManager::Update(EnemyManager* _enemyManager)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		//NULLでない場合,BulletのUpdate関数を行う
		if (bullet[i] != NULL)
		{
			bullet[i]->Update(_enemyManager);

			//弾が画面外に出ていた場合か弾が敵に当たった場合
			if (bullet[i]->Get_isActive() == false)
			{
				//削除してNULLを入れて、また使えるようにする
				delete bullet[i];
				bullet[i] = NULL;
				activeBullet--;
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
//弾が攻撃中かのゲッター
bool BulletManager::Get_IsActive(int i) {
	if (bullet[i] != NULL) {
		return bullet[i]->Get_isActive();
	}

	return false;
}
//弾のx座標ゲッター
float BulletManager::Get_X(int i) {
	if (bullet[i] != NULL) {
		return bullet[i]->Get_x();
	}
}
//弾のy座標ゲッター
float BulletManager::Get_Y(int i) {
	if (bullet[i] != NULL) {
		return bullet[i]->Get_y();
	}
}
//弾のwidthゲッター
float BulletManager::Get_Width(int i) {
	if (bullet[i] != NULL) {
		return bullet[i]->Get_width();
	}
}
//弾のheightゲッター
float BulletManager::Get_Height(int i) {
	if (bullet[i] != NULL) {
		return bullet[i]->Get_height();
	}
}
//弾のアクティブゲッター
int BulletManager::Get_ActiveBullet() {
		return activeBullet;
}
//弾の最大数のゲッター
int BulletManager::Get_MaxBullet() {
	return MAX_BULLET;
}
bool BulletManager::Get_IsHit(int i) {
	if (bullet[i] != NULL) {
		return bullet[i]->Get_isHit();
	}
}
void BulletManager::Set_isActive(int i, bool flg) {

	if (bullet[i] != NULL) {
		bullet[i]->Set_isActive(flg);
	}
}