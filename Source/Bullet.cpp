#include"DxLib.h"
#include"Object.h"
#include"Bullet.h"
#include"Define.h"
#include"BaseEnemy.h"
#include"EnemyManager.h"


Bullet::Bullet(VECTOR& position, int pl_pos, bool pl_attack)
{
	//弾の発生位置
	pos.x = position.x + 12;

	pos.y = position.y + 12;

	//進む方向
	Bullet_Move = pl_pos;

	//発射中かどうか
	isActive = pl_attack;

	//画像
	gh = 0;

	//幅
	width = 24;

	//縦
	height = 24;

	//当たり判定
	isHit = false;
}
Bullet::~Bullet()
{

}
//当たり判定
bool Bullet::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh)
{
	if (mx <= (ox + ow) && my <= (oy + oh) &&
		ox <= (mx + mw) && oy <= (my + mh))
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
	//弾の色
	Cr = GetColor(255, 255, 255);

	//弾の描画
	DrawBox(pos.x, pos.y, pos.x + width, pos.y + height, Cr, TRUE);

	//弾の当たり判定
	DrawBox(Get_x(), Get_y(), pos.x + Get_width(), pos.y + Get_height(), GetColor(255, 0, 0), FALSE);
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
	for (int i = 0; i < _eManager->Get_enemyNum(); i++) {  //エネミー
		if (ClisionHit(Get_x(), Get_y(), Get_width(), Get_height(),
			_eManager->Get_x(i), _eManager->Get_y(i), _eManager->Get_width(i), _eManager->Get_height(i))) 
		{
			isHit = true;
		}
	}
	if (ClisionHit(Get_x(), Get_y(), Get_width(), Get_height(), //メイン城
		900, 480, 94, 94))
	{
		isActive = false;
	}
}
