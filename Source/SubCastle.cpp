#include <DxLib.h>
#include "SubCastle.h"
#include "EnemyManager.h"

//�R���X�g���N�^
SubCastle::SubCastle(int _durability,int _type)
	:BaseCastle(_durability) {
	durability = _durability;

	//���W�ݒ�
	switch (_type)
	{
	case 1:    //����
		width = 50;
		height = 50;
		x = 350  - width;
		y = 450  - height;
		enemyDirection = 0;

		break;

	case 2:    //�E��
		width = 30;
		height = 30;
		x = 850 - width;
		y = 400 - height;
		enemyDirection = 1;

		break;

	case 3:    //�㑤
		width = 60;
		height = 60;
		x = 550 - width;
		y = 250 - height;
		enemyDirection = 2;

		break;

	case 4:    //����
		width = 50;
		height = 50;
		x = 550 - width;
		y = 750 - height;
		enemyDirection = 3;

		break;

	default:
		break;
	}
}

void SubCastle::Update(EnemyManager* enemy)
{
	for (int num = 0; num < enemy->Get_enemyNum(); num++)
	{
		if (enemy->Get_ActiveFlg(num) == true)
		{
			ClisionHit(enemy->Get_x(num), enemy->Get_y(num), enemy->Get_width(num),
				enemy->Get_height(num), enemy->Get_Power(num), num,
				enemy->Get_AttackFlg(num), enemy->Get_ActiveFlg(num));
		}

		if (ClisionHit(enemy->Get_x(num), enemy->Get_y(num), enemy->Get_width(num),
			enemy->Get_height(num), enemy->Get_Power(num), num,
			enemy->Get_AttackFlg(num), enemy->Get_ActiveFlg(num)) == true)
		{
			enemy->Set_IsAttack(num, false);
			enemy->Set_IsActive(num, false);
		}
	}

	//��̏�ԂȂ�
	if (isActive == false)
	{
		EnemyCastle();
	}

}

void SubCastle::Draw()
{
	//�K���ɕ\��
	if (isActive == true)
	{
		DrawBox(x, y, x + width, y + height, GetColor(0, 0, 128), true);
	}
	else
	{
		DrawBox(x, y, x + width, y + height, GetColor(128, 0, 0), true);
	}
}

//���_���_���[�W���󂯂��Ƃ��̏���
bool SubCastle::ClisionHit(float ox, float oy, float ow, float oh,
	int pow, int num, bool attackFlg, bool activeFlg)
{
	if (x + width >= ox && x <= ox + ow &&
		y + height >= oy && y <= oy + oh &&
		attackFlg == true && activeFlg == true)
	{
		//��񂾂�����
		if (isHit == false)
		{
			durability -= pow;
			//�Z�b�g���Ă����Ȃ��Ƌ������Ă���Ȃ�
			Set_Durability(durability);
			isHit = true;
		}

		return true;
	}

	//��񂾂���������p�̃t���O����
	if (isHit == true)
	{
		isHit = false;
	}

	//�ϋv�̏���
	if (durability > 0)
	{
		isActive = true;
	}
	else
	{
		isActive = false;
	}

	//�Z�b�g���Ă����Ȃ��Ƌ������Ă���Ȃ�
	Set_IsActive(isActive);

	return false;
}

void SubCastle::EnemyCastle()
{
	//EnemyManager�ɑ���t����p�����[�^��ݒ�(��������)
	enemySpeed =10;
	enemyPower=1;
	enemyDurability=10;

	Set_EnemySpeed(enemySpeed);
	Set_EnemyPower(enemyPower);
	Set_EnemyDurability(enemyDurability);
	Set_EnemyDirection(enemyDirection);
}

