#include"DxLib.h"
#include"Object.h"
#include"Bullet.h"
#include"Define.h"
#include"BaseEnemy.h"
#include"EnemyManager.h"

Bullet::Bullet(VECTOR& position, int pl_type,int pl_pos, bool pl_attack)
{
	//’e‚Ì”­¶ˆÊ’u
	pos.x = position.x + 12;

	pos.y = position.y + 12;

	//i‚Ş•ûŒü
	Bullet_Move = pl_pos;

	//”­Ë’†‚©‚Ç‚¤‚©
	isActive = pl_attack;

	//‰æ‘œ
	bulletGraph = pl_type;

	//‰æ‘œ‰ñ“]
	graphAngle = 4;

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

	//’e‚Ì•`‰æ   PL * 2 = ¶  PI * 2.5 ã PI* * 3.0 ‰E PI * 4.0 ‰º 
	DrawRotaGraph(pos.x+12, pos.y+12, 1.0,  PI * graphAngle, Image::Instance()->GetGraph(eImageType::Gpicture_Bullet, bulletGraph), TRUE); //‰æ‘œ‚Ì•`‰æ

}
void Bullet::Update(EnemyManager* _eManager)
{

	if (isActive == true) {
		if (Bullet_Move == 0)
		{
			//’e‚ÌŠp“x‚ğ•Ï‚¦‚é
			graphAngle = 2.0;
			pos.x -= 3.0f;
		}
		if (Bullet_Move == 1)
		{
			//’e‚ÌŠp“x‚ğ•Ï‚¦‚é
			graphAngle = 2.5;
			pos.y -= 3.0f;
		}
		if (Bullet_Move == 2)
		{
			//’e‚ÌŠp“x‚ğ•Ï‚¦‚é
			graphAngle = 3.0;
			pos.x += 3.0f;
		}
		if (Bullet_Move == 3)
		{
			//’e‚ÌŠp“x‚ğ•Ï‚¦‚é
			graphAngle = 3.5;
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
	for (int i = 0; i < _eManager->Get_enemyNum(); i++) {  //ƒGƒlƒ~[
		if (ClisionHit(Get_x(), Get_y(), Get_width(), Get_height(),
			_eManager->Get_x(i), _eManager->Get_y(i), _eManager->Get_width(i), _eManager->Get_height(i))) 
		{
			isHit = true;
		}
	}
	if (ClisionHit(Get_x(), Get_y(), Get_width(), Get_height(), //ƒƒCƒ“é
		900, 480, 94, 94))
	{
		isActive = false;
	}
}
