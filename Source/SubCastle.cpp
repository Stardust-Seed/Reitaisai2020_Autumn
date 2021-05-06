#include "DxLib.h"
#include "SubCastle.h"
#include "EnemyManager.h"

//�R���X�g���N�^
SubCastle::SubCastle(int _durability,int _type,int _num)
	:BaseCastle(_durability) {
	durability = _durability;

	width =  48;
	height = 48;
	addPosX = 0;
	addPosY = 0;
	addSize = 8;

	//���W�ݒ�
	switch (_num)
	{
	case 1:    //����

		//���W�ݒ�
		x = COORDINATE_X_ONE;
		y = COORDINATE_Y_ONE;

		addPosX = -48;
		addPosY = -80;

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = x + addPosX;
		popPosY = y + addPosY;

		direction = eDirection::Left;
		break;
	case 2:    //����

        //���W�ݒ�
		x = COORDINATE_X_TWO;
		y = COORDINATE_Y_TWO;

		addPosX = -48;
		addPosY = 32;

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = x + addPosX;
		popPosY = y + addPosY;

		direction = eDirection::Left;
		break;

	case 3:    //�E��

		//���W�ݒ�
		x = COORDINATE_X_THREE;
		y = COORDINATE_Y_THREE;

		addPosX = 32;
		addPosY = -48;

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = x + addPosX;
		popPosY = y + addPosY;

		direction = eDirection::Up;
		break;

	case 4:    //�㑤

		//���W�ݒ�
		x = COORDINATE_X_FOUR;
		y = COORDINATE_Y_FOUR;

		addPosX = -80;
		addPosY = -48;

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = x + addPosX;
		popPosY = y + addPosY;

		direction = eDirection::Up;
		break;

	case 5:    //����

		//���W�ݒ�
		x = COORDINATE_X_FIVE;
		y = COORDINATE_Y_FIVE;

		addPosX = 48;
		addPosY = 32;

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = x + addPosX;
		popPosY = y + addPosY;

		direction = eDirection::Right;
		break;
		
	case 6:    //����

        //���W�ݒ�
		x = COORDINATE_X_SIX;
		y = COORDINATE_Y_SIX;

		addPosX = 48;
		addPosY = -80;

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = x + addPosX;
		popPosY = y + addPosY;

		direction = eDirection::Right;
		break;
	case 7:    //����

        //���W�ݒ�
		x = COORDINATE_X_SEVEN;
		y = COORDINATE_Y_SEVEN;

		addPosX = -80;
		addPosY = 48;

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = x + addPosX;
		popPosY = y + addPosY;

		direction = eDirection::Down;
		break;
	case 8:    //����

        //���W�ݒ�
		x = COORDINATE_X_EIGHT;
		y = COORDINATE_Y_EIGHT;

		addPosX = 32;
		addPosY = 48;

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = x + addPosX;
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