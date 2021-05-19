#include"DxLib.h"
#include"Object.h"
#include"Bullet.h"
#include"Define.h"
#include"BaseEnemy.h"
#include"EnemyManager.h"

Bullet::Bullet(VECTOR& position, int pl_type,eDirection pl_direction, bool pl_attack,int pl_power,int shotpower)
{
	//�e�̔����ʒu
	pos.x = position.x + 12;

	pos.y = position.y + 12;

	//�i�ޕ���
	bullet_Move = pl_direction;

	//���˒����ǂ���
	isActive = pl_attack;


	//�U����
	power = pl_power;

	//�`���[�W�Q�[�W
	shotPower = shotpower;

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
void Bullet::Update(EnemyManager* _eManager,BasePlayer* _basePlayer)
{

	if (isActive == true) {
		//�`���[�W�Q�[�W��MAX�Ȃ�U����UP
		if (shotPower == 100)
		{
			power = 200;
		}
		else
		{
			power = _basePlayer->Get_power();
		}
		if (bullet_Move == eDirection::Left)
		{
			//�e�̊p�x��ς���
			graphAngle = 2.0;
			//�������֔��ł���
			pos.x -= 3.0f;
		}
		if (bullet_Move == eDirection::Up)
		{
			//�e�̊p�x��ς���
			graphAngle = 2.5;
			//������֔��ł���
			pos.y -= 3.0f;
		}
		if (bullet_Move == eDirection::Right)
		{
			//�e�̊p�x��ς���
			graphAngle = 3.0;
			//�E�����֔��ł���
			pos.x += 3.0f;
		}
		if (bullet_Move == eDirection::Down)
		{
			//�e�̊p�x��ς���
			graphAngle = 3.5;
			//�������֔��ł���
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
