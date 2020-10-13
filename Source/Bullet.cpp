#include"DxLib.h"
#include"Object.h"
#include"Bullet.h"
#include"Define.h"
#include"BaseEnemy.h"
#include"EnemyManager.h"

Bullet::Bullet(VECTOR& position, int pl_type,int pl_pos, bool pl_attack)
{
	//�e�̔����ʒu
	pos.x = position.x + 12;

	pos.y = position.y + 12;

	//�i�ޕ���
	Bullet_Move = pl_pos;

	//���˒����ǂ���
	isActive = pl_attack;

	//�摜
	bulletGraph = pl_type;

	//�摜��]
	graphAngle = 4;

	//��
	width = 24;

	//�c
	height = 24;

	//�����蔻��
	isHit = false;
}
Bullet::~Bullet()
{

}
//�����蔻��
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

	//�e�̕`��   PL * 2 = ��  PI * 2.5 �� PI* * 3.0 �E PI * 4.0 �� 
	DrawRotaGraph(pos.x+12, pos.y+12, 1.0,  PI * graphAngle, Image::Instance()->GetGraph(eImageType::Gpicture_Bullet, bulletGraph), TRUE); //�摜�̕`��

}
void Bullet::Update(EnemyManager* _eManager)
{

	if (isActive == true) {
		if (Bullet_Move == 0)
		{
			//�e�̊p�x��ς���
			graphAngle = 2.0;
			pos.x -= 3.0f;
		}
		if (Bullet_Move == 1)
		{
			//�e�̊p�x��ς���
			graphAngle = 2.5;
			pos.y -= 3.0f;
		}
		if (Bullet_Move == 2)
		{
			//�e�̊p�x��ς���
			graphAngle = 3.0;
			pos.x += 3.0f;
		}
		if (Bullet_Move == 3)
		{
			//�e�̊p�x��ς���
			graphAngle = 3.5;
			pos.y += 3.0f;
		}
	}

	//��ʊO�ɏo����t���O��false�ɂ���
	if (pos.x > GAME_WIDTH || pos.x < 0)
	{
		isActive = false;
	}
	if (pos.y > GAME_HEIHGT || pos.y < 0)
	{
		isActive= false;
	}
	for (int i = 0; i < _eManager->Get_enemyNum(); i++) {  //�G�l�~�[
		if (ClisionHit(Get_x(), Get_y(), Get_width(), Get_height(),
			_eManager->Get_x(i), _eManager->Get_y(i), _eManager->Get_width(i), _eManager->Get_height(i))) 
		{
			isHit = true;
		}
	}
	if (ClisionHit(Get_x(), Get_y(), Get_width(), Get_height(), //���C����
		900, 480, 94, 94))
	{
		isActive = false;
	}
}
