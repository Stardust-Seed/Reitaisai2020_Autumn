#include"DxLib.h"
#include"Object.h"
#include"Bullet.h"
#include"Define.h"
#include"BaseEnemy.h"
#include"EnemyManager.h"


Bullet::Bullet(VECTOR& position, int pl_pos, bool pl_attack)
{
	//弾の発生位置
	pos = position;

	//進む方向
	Bullet_Move = pl_pos;

	//当たり判定
	isHit = false;

	//発射中かどうか
	isActive = pl_attack;

	//攻撃力
	power = 1;

	//画像
	gh = 0;
}
Bullet::~Bullet()
{

}
//当たり判定
bool Bullet::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh)
{
	if (mx < (ox + ow) && my < (oy + oh) &&
		ox < (mx + mw) && oy < (my + mh))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Bullet::Draw()
{
	//弾の描画
	Cr = GetColor(255, 255, 255);
	DrawCircle(pos.x + 24, pos.y + 24, 5.0, Cr, TRUE);
}
void Bullet::Update(EnemyManager* _eManager)
{
	if (isActive == true) {
		if (Bullet_Move == 0)
		{
			pos.x -= 3.0f;
		}
		if (Bullet_Move == 1)
		{
			pos.y -= 3.0f;
		}
		if (Bullet_Move == 2)
		{
			pos.x += 3.0f;
		}
		if (Bullet_Move == 3)
		{
			pos.y += 3.0f;
		}
	}

	//画面外に出たらフラグをfalseにする
	if (pos.x > GAME_WIDTH || pos.x < 0)
	{
		isActive = false;
	}
	if (pos.y > GAME_HEIHGT || pos.y < 0)
	{
		isActive= false;
	}
	for (int i = 0; i < _eManager->Get_ActiveCount(); i++) {
		isHit = ClisionHit(Get_x(), Get_y(), Get_width(), Get_height(),
			_eManager->Get_x(i), _eManager->Get_y(i), _eManager->Get_width(i), _eManager->Get_height(i));
	}
	if (isHit == true)
	{
		isActive = false;
	}

}
