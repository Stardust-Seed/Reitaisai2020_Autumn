#include"DxLib.h"
#include"Object.h"
#include"Bullet.h"
#include"Define.h"
#include"BaseEnemy.h"
#include"EnemyManager.h"


Bullet::Bullet(VECTOR& position, int pl_pos, bool pl_attack)
{
	//’e‚Ì”­¶ˆÊ’u
	pos.x = position.x + 12;

	pos.y = position.y + 12;

	//i‚Ş•ûŒü
	Bullet_Move = pl_pos;

	//”­Ë’†‚©‚Ç‚¤‚©
	isActive = pl_attack;

	//‰æ‘œ
	gh = 0;

	//•
	width = 24;

	//c
	height = 24;

	//“–‚½‚è”»’è
	isHit = false;
}
Bullet::~Bullet()
{

}
//“–‚½‚è”»’è
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
	//’e‚ÌF
	Cr = GetColor(255, 255, 255);

	//’e‚Ì•`‰æ
	DrawBox(pos.x, pos.y, pos.x + width, pos.y + height, Cr, TRUE);

	//’e‚Ì“–‚½‚è”»’è
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

	//‰æ–ÊŠO‚Éo‚½‚çƒtƒ‰ƒO‚ğfalse‚É‚·‚é
	if (pos.x > GAME_WIDTH || pos.x < 0)
	{
		isActive = false;
	}
	if (pos.y > GAME_HEIHGT || pos.y < 0)
	{
		isActive= false;
	}
	for (int i = 0; i < _eManager->Get_enemyNum(); i++) {
		if (ClisionHit(Get_x(), Get_y(), Get_width(), Get_height(),
			_eManager->Get_x(i), _eManager->Get_y(i), _eManager->Get_width(i), _eManager->Get_height(i)))
		{
			isHit = true;
		}
	}
	if (isHit == true)
	{
		DrawFormatString(0, 150, GetColor(255, 255, 255), "‚¤‚ç‚×‚¦‚¦‚¦‚¦‚¦‚¦", 0);
		isActive = false;
	}

}
