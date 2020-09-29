#include "DxLib.h"
#include "SubCastle.h"
#include "EnemyManager.h"

//�R���X�g���N�^
SubCastle::SubCastle(int _durability,int _type)
	:BaseCastle(_durability) {
	durability = _durability;
	SRand;					//����������
	
	width =  48;
	height = width;

	addPosX = 0;
	addPosY = 0;
	addSize = 12;

	int posType = GetRand(1);

	//���W�ݒ�
	switch (_type)
	{
	case 1:    //����

		x = GAME_WIDTH / 2 - width / 2 - 200 - GetRand(50);
		y = GAME_HEIHGT / 2 - height / 2;

		if (posType == 0)    //��
		{
			addPosY = -60;
		}
		else                 //��
		{
			addPosY = 60;
		}

		direction = eDirection::Left;

		break;

	case 2:    //�E��

		x = GAME_WIDTH / 2 - width / 2 + 200 + GetRand(50);
		y = GAME_HEIHGT / 2 - height / 2;

		if (posType == 0)    //��
		{
			addPosY = -60;
		}
		else                 //��
		{
			addPosY = 60;
		}

		direction = eDirection::Right;



		break;

	case 3:    //�㑤

		x = GAME_WIDTH / 2 - width / 2;
		y = GAME_HEIHGT / 2 - height / 2 - 200 - GetRand(30);

		if (posType == 0)    //��
		{
			addPosX = -60;
		}
		else                 //�E
		{
			addPosX = 60;
		}

		direction = eDirection::Up;

		break;

	case 4:    //����

		x = GAME_WIDTH / 2 - width / 2;
		y = GAME_HEIHGT / 2 - height / 2 + 200 + GetRand(30);

		if (posType == 0)    //��
		{
			addPosX = -60;
		}
		else                 //�E
		{
			addPosX = 60;
		}

		direction = eDirection::Down;

		break;

	default:
		break;
	}
}

void SubCastle::Update(EnemyManager* enemy)
{
	for (int num = 0; num < enemy->Get_enemyNum(); num++)
	{
		if (enemy->Get_ActiveFlg(num) == true && enemy->Get_AttackType(num) != eAttackType::Player &&
			enemy->Get_AttackFlg(num) == true)
		{
			ClisionHit(enemy->Get_x(num),		  enemy->Get_y(num)         , enemy->Get_width(num),
				       enemy->Get_height(num),    enemy->Get_Power(num)     , num,
				       enemy->Get_AttackFlg(num), enemy->Get_ActiveFlg(num));
		}
	}

	//��񂾂���������p�̃t���O����
	if (isHit == true)
	{
		isHit = false;
	}

	//�ϋv�̏���
	if (durability <= 0)
	{
		isActive = false;
	}
}

void SubCastle::Draw()
{
	//�K���ɕ\��
	if (isActive == true)
	{
		DrawGraph(x + addPosX - addSize / 2, y + addPosY - addSize / 2,
		Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 0), TRUE);
	}
	else
	{
		DrawGraph(x + addPosX - addSize / 2, y + addPosY - addSize / 2,
		Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 1), TRUE);
	}
}


