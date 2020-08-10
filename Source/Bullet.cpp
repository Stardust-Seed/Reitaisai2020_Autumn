#include"DxLib.h"
#include"Object.h"
#include"Bullet.h"
#include"Define.h"
#include"BaseEnemy.h"


Bullet::Bullet(VECTOR& position, int pl_pos, bool pl_attack)
{
	//�e�̔����ʒu
	pos = position;

	//�i�ޕ���
	Bullet_Move = pl_pos;

	//���˒����ǂ���
	Bullet_Attack = pl_attack;

	//�摜
	gh = 0;
}
Bullet::~Bullet()
{

}
//�����蔻��
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
	//�e�̕`��
	Cr = GetColor(255, 255, 255);
	DrawCircle(pos.x + 24, pos.y + 24, 5.0, Cr, TRUE);
}
void Bullet::Update()
{
	if (Bullet_Attack == true) {
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

	//��ʊO�ɏo����t���O��false�ɂ���
	if (pos.x > GAME_WIDTH || pos.x < 0)
	{
		Bullet_Attack = false;
	}
	if (pos.y > GAME_HEIHGT || pos.y < 0)
	{
		Bullet_Attack = false;
	}

	//isHit = ClisionHit(Get_x(), Get_y(), Get_width(), Get_height(),
	//	baseEnemy->Get_X(), baseEnemy->Get_Y(), baseEnemy->Get_Width(), baseEnemy->Get_Height());


}
