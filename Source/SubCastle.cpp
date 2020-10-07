#include "DxLib.h"
#include "SubCastle.h"
#include "EnemyManager.h"

//�R���X�g���N�^
SubCastle::SubCastle(int _durability,int _type)
	:BaseCastle(_durability) {
	durability = _durability;

	width =  48;
	height = 48;
	addPosX = 0;
	addPosY = 0;
	addSize = 8;

	int posType = GetRand(1);

	//���W�ݒ�
	switch (_type)
	{
	case 1:    //����

		//���W�ݒ�
		x = GAME_WIDTH / 2 - width / 2 - 225 - GetRand(30);
		y = GAME_HEIHGT / 2 - height / 2;

		//�ǉ��̍��W�ݒ�
		if (posType == 0)    //��
		{
			addPosX = -48;
			addPosY = -65;

		}
		else                 //��
		{
			addPosX = -48;
			addPosY = 53;
		}

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = x + addPosX;
		popPosY = y;

		direction = eDirection::Left;

		break;

	case 2:    //�E��

		//���W�ݒ�
		x = GAME_WIDTH / 2 - width / 2 + 225 + GetRand(30);
		y = GAME_HEIHGT / 2 - height / 2;

		//�ǉ��̍��W�ݒ�
		if (posType == 0)    //��
		{
			addPosX = 48;
			addPosY = -65;
		}
		else                 //��
		{
			addPosX = 48;
			addPosY = 53;
		}

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = x + addPosX;
		popPosY = y;

		direction = eDirection::Right;

		break;

	case 3:    //�㑤

		//���W�ݒ�
		x = GAME_WIDTH / 2 - width / 2;
		y = GAME_HEIHGT / 2 - height / 2 - 225 - GetRand(30);

		//�ǉ��̍��W�ݒ�
		if (posType == 0)    //��
		{
			addPosY = -48;
			addPosX = -54;
		}
		else                 //�E
		{
			addPosY = -48;
			addPosX = 55;
		}

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = x;
		popPosY = y + addPosY;

		direction = eDirection::Up;

		break;

	case 4:    //����

		//���W�ݒ�
		x = GAME_WIDTH / 2 - width / 2;
		y = GAME_HEIHGT / 2 - height / 2 + 225 + GetRand(30);

		//�ǉ��̍��W�ݒ�
		if (posType == 0)    //��
		{
			addPosY = 48;
			addPosX = -54;
		}
		else                 //�E
		{
			addPosY = 48;
			addPosX = 55;
		}

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = x;
		popPosY = y + addPosY;

		direction = eDirection::Down;

		break;

	default:
		break;
	}
	//�T�u���_�̕\���ꏊ�̍��W�ݒ�
	drawPosX = x + addPosX - addSize / 2;
	drawPosY = y + addPosY - addSize / 2;

}

void SubCastle::Update(EnemyManager* enemy)
{
	//�����蔻��
	for (int num = 0; num < enemy->Get_enemyNum(); num++)
	{
		if (enemy->Get_ActiveFlg(num) == true && enemy->Get_AttackFlg(num) == true  &&
			enemy->Get_AttackType(num) != eAttackType::Player)
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
		DrawGraphF(drawPosX,drawPosY,Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 0), TRUE);
	}
	else
	{
		DrawGraphF(drawPosX, drawPosY, Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 1), TRUE);
	}
}